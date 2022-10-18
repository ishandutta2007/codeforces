#include <bits/stdc++.h>
const long long ouuan=998244353;
long long fac;
int n;

long long qpow(long long a, int b) {
	if (b==0) return 1;
	long long d=qpow(a, b>>1);
	d=(d*d)%ouuan;
	if (b&1) d=(d*a)%ouuan;
	return d;
}

long long inverse(long long p) {
	return qpow(p, ouuan-2);
}

long long gfrac(long long a, long long b) {
	return a*inverse(b)%ouuan;
}

int main() {
	scanf("%d",&n); fac=1;
	if (n==1) {printf("1");return 0;}
	if (n==2) {printf("2");return 0;}
	for (int i=1;i<=n;++i) fac=(fac*i)%ouuan;
	long long ans=0;
	for (int i=n-1;i>=2;i--) {
		long long np=fac*gfrac(n-i, n-i+1)%ouuan;
		//long long np=fac/(n-i+1)*(n-i);
		np=(np*i)%ouuan;
		ans=(ans+np)%ouuan;
		fac=(fac*gfrac(1, n-i+1))%ouuan;
		//fac=fac/(n-i+1);
	//	printf("%d ", fac);
	}std::cout<<(ans+fac)%ouuan;
}