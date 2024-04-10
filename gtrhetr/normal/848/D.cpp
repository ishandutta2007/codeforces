#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll f[60][60],g[60][60],h[60][60],inv[60];
int n,m,M;

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
	n=rd();M=rd();m=n+1;
	f[0][1]=1;h[0][0]=1;
	inv[1]=1;
	for (int i=2;i<=55;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
	{
		for (int k1=0;k1<i;k1++)
		{
			int k2=i-1-k1;
			g[i][j]=(g[i][j]+f[k1][j]*f[k2][j])%mod;
			for (int l=j+1;l<=m;l++) g[i][j]=(g[i][j]+f[k1][j]*f[k2][l])%mod;
			for (int l=j+1;l<=m;l++) g[i][j]=(g[i][j]+f[k1][l]*f[k2][j])%mod;
		}
		for (int k=n;k>=i;k--) for (int l=m;l>=j;l--)
		{
			ll now=1;
			for (int t=1,mx=min(k/i,l/j);t<=mx;t++)
			{
				now=now*(g[i][j]+t-1)%mod*inv[t]%mod;
				h[k][l]=(h[k][l]+h[k-i*t][l-j*t]*now)%mod;
			}
		}
		f[i][j]=h[i][j-1];
	}
	printf("%lld\n",f[n][M]);
	return 0;
}