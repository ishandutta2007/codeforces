#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

int cnt[110],n,k,m;

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

struct matrix
{
	ll a[260][260];int n;
	matrix() {}
	matrix(int nn):n(nn) { memset(a,0,sizeof(a)); }
};

inline matrix operator *(const matrix &x,const matrix &y)
{
	matrix res(x.n);
	for (int i=1;i<=x.n;i++) for (int j=1;j<=x.n;j++) for (int k=1;k<=x.n;k++)
		res.a[i][j]=pls(res.a[i][j],x.a[i][k]*y.a[k][j]%mod);
	return res;
}

inline matrix ksm(matrix x,int y)
{
	matrix res(x.n);
	for (int i=1;i<=res.n;i++) res.a[i][i]=1;
	for (;y;y>>=1,x=x*x) if (y&1) res=res*x;
	return res;
}

inline int calc(const int &x,const int &y) { return (x<<m)+y+1; }

int main()
{
	n=rd();k=rd();m=rd();
	matrix now((k+1)<<m);
	int mx=((1<<m)-1);
	for (int i=1;i<=mx;i++) cnt[i]=cnt[i>>1]+(i&1);
	for (int i=0;i<=k;i++)
	{
		for (int j=0;j<(1<<m);j++) now.a[calc(i,j)][calc(i,(j<<1)&mx)]++;
		if (i==k) continue;
		for (int j=0;j<(1<<m);j++) now.a[calc(i,j)][calc(i+1,((j<<1)|1)&mx)]+=cnt[j]+1;
	}
	now=ksm(now,n);
	matrix res((k+1)<<m);
	res.a[1][calc(0,0)]=1;
	res=res*now;
	ll ans=0;
	for (int i=0;i<=mx;i++) ans=pls(ans,res.a[1][calc(k,i)]);
	printf("%lld\n",ans);
	return 0;
}