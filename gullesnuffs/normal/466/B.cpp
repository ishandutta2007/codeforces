#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, a, b;
	scanf("%I64d%I64d%I64d", &n, &a, &b);
	n*=6;
	long long best=1000000000000000005LL;
	long long bestA, bestB;
	for(int i=0; i < 100000; ++i){
		long long A=a+i;
		long long B=(n+A-1)/A;
		if(B < b)
			B=b;
		if(A*B < best){
			best=A*B;
			bestA=A;
			bestB=B;
		}
	}
	for(int i=0; i < 100000; ++i){
		long long B=b+i;
		long long A=(n+B-1)/B;
		if(A < a)
			A=a;
		if(A*B < best){
			best=A*B;
			bestA=A;
			bestB=B;
		}
	}
	printf("%I64d\n%I64d %I64d\n", best, bestA, bestB);
}