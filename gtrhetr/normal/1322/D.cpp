#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL

ll f[4010][2010],g[4010][2010];
int len[2010];
int l[2010],s[2010],c[4010],n,m,tt;

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline ll gao(int x,int l,int r)
{
	ll ans=0;
	for (int i=l;i<=r;i++)
	{
		ans+=(ll)c[i]*x;x>>=1;
		if (!x) break;
	}
	return ans;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) l[i]=rd();
	for (int i=1;i<=n;i++) s[i]=rd();
	for (int i=1;i<=n+m;i++) c[i]=rd();
	for (int i=0;i<=n+m;i++) for (int j=1;j<=n;j++) f[i][j]=-inf;
	for (int i=0;i<=n+m;i++) for (int j=0;j<=n;j++) g[i][j]=0;
	for (int i=n;i;i--)
	{
		for (int j=len[l[i]];j>=0;j--) f[l[i]][j+1]=max(f[l[i]][j+1],f[l[i]][j]-s[i]);
		len[l[i]]++;
		for (int j=l[i]-1;j>=0;j--)
		{
			int hh=l[i]-j,hhh=(hh>=20)?n:min(n,(1<<hh)-1);
			f[l[i]][1]=max(f[l[i]][1],g[j][hhh]-s[i]);
			for (int k=hhh+1;k<=len[j];k++)
			{
				f[l[i]][(k>>hh)+1]=max(f[l[i]][(k>>hh)+1],f[j][k]-s[i]+gao(k,j,l[i]-1));
				len[l[i]]=max(len[l[i]],(k>>hh)+1);
			}
		}
		g[l[i]][0]=f[l[i]][0];
		for (int j=1;j<=n;j++)
		{
			if (j>len[l[i]]) g[l[i]][j]=g[l[i]][j-1];
			else g[l[i]][j]=max(g[l[i]][j-1],f[l[i]][j]+gao(j,l[i],n+m));
		}
	}
	ll ans=0;
	for (int i=0;i<=n+m;i++) ans=max(ans,g[i][n]);
	printf("%lld\n",ans);
	return 0;
}