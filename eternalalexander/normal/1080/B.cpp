#include <cstdio>
#include <iostream>

long long calc(long long x) {
	if (x==0) return 0;
	return (2+x/2*2)*x/2-(1+(x-1)/2*2+1)*(x+1)/2;
}

int main() {
	long long l, r;
	int q; scanf("%d", &q);
	while (q--) {
		std::cin>>l>>r;
		std::cout<<calc(r)-calc(l-1)<<std::endl;
	}
			
	return 0;
}