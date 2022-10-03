#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll inf=1048575;

ll cnt[1048576],n,p;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline ll gao(ll x) { return cnt[x&inf]+cnt[(x>>20)&inf]; }

int main()
{
	n=rd();p=rd();
	for (int i=1;i<1048576;i++) cnt[i]=cnt[i>>1]+(i&1);
	if (p==0)
	{
		printf("%lld\n",gao(n));
		return 0;
	}
	if (p>0)
	{
		for (int i=1;i<=n/p;i++) if (gao(n-i*p)<=i&&n-i*p>=i) { printf("%d\n",i);return 0; }
		puts("-1");
		return 0;
	}
	for (int i=1;i<=60;i++) if (gao(n-i*p)<=i&&n-i*p>=i) { printf("%d\n",i);return 0; }
	puts("-1");
	return 0;
}