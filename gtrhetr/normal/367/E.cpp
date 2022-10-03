#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int f[2][350][350],g[350][350],n,m,x;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int pls(const int &x,const int &y) { return (x+y<mod)?x+y:x+y-mod; }

int main()
{
	n=rd();m=rd();x=rd();
	if (n>m) { puts("0");return 0; }
	f[0][0][0]=1;int cur=0;
	for (int i=0;i<m;i++)
	{
		cur^=1;
		for (int j=0;j<=n;j++) for (int k=0;k<=n;k++) f[cur][j][k]=g[j][k]=0;
		for (int j=0;j<=n;j++) for (int k=0;k<=j;k++) if (f[cur^1][j][k])
		{
			g[j][k]=pls(g[j][k],f[cur^1][j][k]);
			if (k) g[j][k-1]=pls(g[j][k-1],f[cur^1][j][k]);
		}
		if (i+1==x)
		{
			for (int j=0;j<n;j++) for (int k=0;k<=j;k++) f[cur][j+1][k+1]=g[j][k];
		}
		else
		{
			for (int j=0;j<=n;j++) for (int k=0;k<=j;k++) if (g[j][k])
			{
				if (j<n) f[cur][j+1][k+1]=pls(f[cur][j+1][k+1],g[j][k]);
				f[cur][j][k]=pls(f[cur][j][k],g[j][k]);
			}
		}
	}
	int ans=pls(f[cur][n][0],f[cur][n][1]);
	for (int i=2;i<=n;i++) ans=(ll)ans*i%mod;
	printf("%d\n",ans);
	return 0;
}