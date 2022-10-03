#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10007

int f[310][310][310],g[310],n,m,tt;
char s[310];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int pls(const int &x,const int &y) { return (x+y<mod)?x+y:x+y-mod; }
inline int mns(const int &x,const int &y) { return (x-y<0)?x-y+mod:x-y; }

struct matrix
{
	ll a[310][310];
	matrix() { memset(a,0,sizeof(a)); }
}ans,now;

inline matrix operator *(const matrix &x,const matrix &y)
{
	matrix res;
	for (int i=0;i<=tt;i++) for (int k=i;k<=tt;k++) if (x.a[i][k]) for (int j=k;j<=tt;j++) res.a[i][j]+=x.a[i][k]*y.a[k][j];
	for (int i=0;i<=tt;i++) for (int j=i;j<=tt;j++) res.a[i][j]?(res.a[i][j]%=mod):0;
	return res;
}

inline matrix ksm(matrix x,int y)
{
	matrix res;
	for (int i=0;i<=tt;i++) res.a[i][i]=1;
	for (;y;y>>=1,x=x*x) if (y&1) res=res*x;
	return res;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);m=rd();
	f[1][n][0]=1;
	for (int i=1;i<=n;i++) for (int j=n;j>=i;j--)
	{
		if (s[i]==s[j])
		{
			if (i+1<j) for (int k=0;k<=i+n-j;k++) f[i+1][j-1][k]=pls(f[i+1][j-1][k],f[i][j][k]);
			else for (int k=0;k<=i+n-j;k++) g[k]=pls(g[k],f[i][j][k]);
		}
		else
		{
			for (int k=0;k<=i+n-j;k++)
			{
				f[i+1][j][k+1]=pls(f[i+1][j][k+1],f[i][j][k]);
				f[i][j-1][k+1]=pls(f[i][j-1][k+1],f[i][j][k]);
			}
		}
	}
	tt=n+((n+1)>>1)+1;
	ans.a[0][1]=1;ans.a[0][tt-((n+1)>>1)]=g[0];
	for (int i=1;i<=n;i++)
	{
		now.a[i][i]=24;now.a[i][tt-((n-i+1)>>1)]=g[i];
		if (i<n) now.a[i][i+1]=1;
	}
	for (int i=n+1;i<tt;i++) now.a[i][i]=25,now.a[i][i+1]=1;
	now.a[tt][tt]=26;
	if (!((n+m)&1))
	{
		ans=ans*ksm(now,(n+m)>>1);
		printf("%d\n",ans.a[0][tt]);
	}
	else
	{
		ans=ans*ksm(now,(n+m+1)>>1);
		int res=ans.a[0][tt];
		memset(ans.a,0,sizeof(ans.a));
		memset(now.a,0,sizeof(now.a));
		memset(g,0,sizeof(g));
		for (int i=1;i<n;i++) if (s[i]==s[i+1]) for (int k=0;k<=n;k++) g[k]=pls(g[k],f[i][i+1][k]);
		ans.a[0][1]=1;ans.a[0][tt-((n+1)>>1)]=g[0];
		for (int i=1;i<=n;i++)
		{
			now.a[i][i]=24;now.a[i][tt-((n-i+1)>>1)]=g[i];
			if (i<n) now.a[i][i+1]=1;
		}
		for (int i=n+1;i<tt;i++) now.a[i][i]=25,now.a[i][i+1]=1;
		ans=ans*ksm(now,(n+m+1)>>1);
		printf("%d\n",mns(res,ans.a[0][tt]));
	}
	return 0;
}