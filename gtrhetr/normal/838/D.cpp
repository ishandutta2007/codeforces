#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

int n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

int main()
{
	n=rd();m=rd();
	printf("%lld\n",(n+1-m)*ksm(n+1,mod-2)%mod*ksm(n*2+2,m)%mod);
	return 0;
}