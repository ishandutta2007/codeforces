#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll k;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main()
{
	k=rd();
	puts("2000");
	printf("-1 ");
	ll sum=k+2000;
	for (int i=2;i<=2000;i++)
	{
		ll hh=min(1000000LL,sum);
		printf("%lld ",hh);
		sum-=hh;
	}
	puts("");
	return 0;
}