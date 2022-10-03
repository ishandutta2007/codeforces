#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

ll f[510][510];
int num[1000010],n,m;

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
	for (int i=1;i<=m;i++) num[i]=rd();
	for (int i=1;i<=n;i++) f[i][i]=1;
	for (int i=1;i<=n+1;i++) f[i][i-1]=1;
	for (int len=1;len<=n;len++) for (int i=1;i+len-1<=n;i++)
	{
		int j=i+len-1,id=i;
		for (int k=i;k<=j;k++) if (num[k]<num[id]) id=k;
		ll res1=0,res2=0;
		for (int k=i;k<=id;k++) res1=pls(res1,f[i][k-1]*f[k][id-1]%mod);
		for (int k=id;k<=j;k++) res2=pls(res2,f[id+1][k]*f[k+1][j]%mod);
		f[i][j]=res1*res2%mod;
	}
	printf("%lld\n",f[1][n]);
	return 0;
}