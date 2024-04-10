#include <cstdio>
#include <iostream>

long long n, k;

int main() {
	std::cin>>n>>k;
	std::cout<<((n*2-1)/k+1+(n*5-1)/k+1+(n*8-1)/k+1);
	return 0;
}