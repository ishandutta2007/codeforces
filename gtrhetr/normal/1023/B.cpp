#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();k=rd();
	if (k<=n) { printf("%lld\n",(k-1)/2);return 0; }
	if (n+(n-1)<k) { puts("0");return 0; }
	ll hh=k-n;
	printf("%lld\n",(k-1)/2-(hh-1));
	return 0;
}