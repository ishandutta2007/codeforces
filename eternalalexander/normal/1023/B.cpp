#include <cstdio>
#include <iostream>
#include <algorithm>


int main() {
	long long n, k;
	std::cin >> n >> k;
	long long high =std::min(k-1, n);
	long long low = k-high;
	std::cout << ((high-low+1)/2>0?(high-low+1)/2:0);
	return 0;
}