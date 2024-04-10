#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll f[100010];
int n,m;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline ll gao(int n,int m)
{
	f[1]=2;f[2]=4;
	for (int i=3;i<=m;i++) f[i]=pls(f[i-1],f[i-2]);
	return f[m]%mod;
}

int main()
{
	n=rd();m=rd();
	if (n>m) swap(n,m);
	printf("%lld\n",mns(pls(gao(n,m),gao(m,n)),2));
	return 0;
}