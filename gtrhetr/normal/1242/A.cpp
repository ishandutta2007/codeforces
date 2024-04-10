#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	if (n==1) { puts("1");return 0; }
	ll hh=n,id=0;
	int cnt=0;
	for (ll i=2;i*i<=n;i++) if (hh%i==0)
	{
		cnt++;id=i;
		while (hh%i==0) hh/=i;
	}
	if (hh>1) cnt++,id=hh;
	if (cnt>1) puts("1");
	else printf("%lld\n",id);
	return 0;
}