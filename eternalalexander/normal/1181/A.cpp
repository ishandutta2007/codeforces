#include <bits/stdc++.h>

long long x,y,z;

int main() {
	std::cin>>y>>z>>x;
	long long res=(y+z)/x;
	std::cout<<res<<" ";
	long long a=y%x,b=z%x;
	if (a+b<x) std::cout<<0;
	else std::cout<<std::min(x-a,x-b);
	return 0;
}