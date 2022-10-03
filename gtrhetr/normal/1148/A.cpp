#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a,b,c;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main()
{
	a=rd();b=rd();c=rd();
	if (a==b) printf("%lld\n",a+b+c*2);
	else if (a>b) printf("%lld\n",b+1+b+c*2);
	else printf("%lld\n",a+a+1+c*2);
	return 0;
}