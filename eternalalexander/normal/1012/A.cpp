#include <cstdio>
#include <iostream>
#include <algorithm>

int n;
int A[300050];

int main() {
	scanf("%d", &n);
	n*=2;
	for (int i=1;i<=n;++i) scanf("%d", &A[i]);
	std::sort(A+1, A+n+1);
	long long ans=(long long)(A[n/2]-A[1])*(long long)(A[n]-A[n/2+1]);
	//std::cout << (long long)(A[n/2]-A[1]) <<(long long)(A[n]-A[n/2+1]); ;
	for (int i=2;i+(n>>1)<=n;++i) {
	//	printf("%d %d %d %d\n", i, i+(n>>1), A[i], A[i+(n>>1)-1]);
		ans=std::min(ans, (long long)(A[n]-A[1])*(long long)(A[i+(n>>1)-1]-A[i]));
	}std::cout << ans;
	return  0;
}