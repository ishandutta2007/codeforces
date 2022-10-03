#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll c1[2010][2010],c2[2010][2010];
int bo[2010][2010],s1[2010][2010],s2[2010][2010],n,m;
char s[2010];

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
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) bo[i][j]=(s[j]=='R');
	}
	if (n==1||m==1)
	{
		bool flag=true;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (bo[i][j]) flag=false;
		printf("%d\n",flag);
		return 0;
	}
	for (int i=1;i<=n;i++) for (int j=m;j;j--) s1[i][j]=s1[i][j+1]+bo[i][j];
	for (int i=n;i;i--) for (int j=1;j<=m;j++) s2[i][j]=s2[i+1][j]+bo[i][j];
	c1[1][1]=1;c1[2][1]=mod-1;
	c2[1][1]=1;c2[1][2]=mod-1;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
	{
		c1[i][j]=pls(c1[i][j],c1[i-1][j]);
		c2[i][j]=pls(c2[i][j],c2[i][j-1]);
		int hh=s1[i][j+1];
		c2[i][j+1]=pls(c2[i][j+1],c1[i][j]);
		c2[i][m-hh+1]=mns(c2[i][m-hh+1],c1[i][j]);
		hh=s2[i+1][j];
		c1[i+1][j]=pls(c1[i+1][j],c2[i][j]);
		c1[n-hh+1][j]=mns(c1[n-hh+1][j],c2[i][j]);
	}
	printf("%lld\n",pls(c1[n][m],c2[n][m]));
	return 0;
}