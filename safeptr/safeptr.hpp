#pragma once
#ifndef SAFEPTR_SIZE_LESS_ERRMSG
#define SAFEPTR_SIZE_LESS_ERRMSG "Size of pointer must be greater than 0"
#endif
#include <stdexcept>
template<typename T>
class OnlyPointer {
	size_t size;
	T* ptr;
public:
	OnlyPointer(size_t size):size(size) {
		if(size <= 0)throw std::invalid_argument(SAFEPTR_SIZE_LESS_ERRMSG);
		if (size == 1) {
			ptr = new T;
		}
		else {
			ptr = new T[size];
		}
	}
	OnlyPointer(const OnlyPointer& old){
		size = old.size;
		ptr = new T[size];
		for (size_t i = 0; i < size; i++) {
			ptr[i] = old.ptr[i];
		}
	}
	~OnlyPointer() {
		destroy();
	}
	
	void reset(T* p = nullptr) {
		if (size == 1) {
			delete ptr;
		}
		else {
			delete[] ptr;
		}
		ptr = p;
	}
	
};