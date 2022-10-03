#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[510][510],mod;
int fa[20010],id[20010],n,m,tt;
char s[110][110];

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

inline int calc(int x,int y) { return (x-1)*(m+1)+y; }

inline int find(int x) { return (x==fa[x])?x:fa[x]=find(fa[x]); }

inline void merge(int x,int y)
{
	x=find(x);y=find(y);
	if (x==y) { puts("0");exit(0); }
	fa[x]=y;
}

inline void add(int x,int y)
{
	if (x==y) return;
	a[x][x]++;a[y][y]++;
	a[x][y]=mns(a[x][y],1);
	a[y][x]=mns(a[y][x],1);
}

inline ll gao(int n)
{
	ll res=1;
	for (int i=1;i<=n;i++)
	{
		int id=0;
		for (int j=i;j<=n;j++) if (a[j][i]) id=j;
		if (!id) return 0;
		if (id^i) res=mod-res;
		swap(a[i],a[id]);
		res=res*a[i][i]%mod;
		for (int j=i+1;j<=n;j++) if (a[j][i])
		{
			ll now=a[j][i]*ksm(a[i][i],mod-2)%mod;
			for (int k=i;k<=n;k++) a[j][k]=mns(a[j][k],a[i][k]*now%mod);
		}
	}
	return res;
}

int main()
{
	n=rd();m=rd();mod=rd();
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n+1;i++) for (int j=1;j<=m+1;j++) fa[calc(i,j)]=calc(i,j);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (s[i][j]!='*')
	{
		if (s[i][j]=='\\') merge(calc(i,j),calc(i+1,j+1));
		else merge(calc(i,j+1),calc(i+1,j));
	}
	int tt=0;
	for (int i=1;i<=n+1;i++) for (int j=1;j<=m+1;j++) if (!((i+j)&1)&&find(calc(i,j))==calc(i,j)) id[calc(i,j)]=++tt;
	memset(a,0,sizeof(a));
	ll ans=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (s[i][j]=='*')
	{
		if (!((i+j)&1)) add(id[find(calc(i,j))],id[find(calc(i+1,j+1))]);
		else add(id[find(calc(i+1,j))],id[find(calc(i,j+1))]);
	}
	ans=pls(ans,gao(tt-1));
	tt=0;
	for (int i=1;i<=n+1;i++) for (int j=1;j<=m+1;j++) if (((i+j)&1)&&find(calc(i,j))==calc(i,j)) id[calc(i,j)]=++tt;
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (s[i][j]=='*')
	{
		if (((i+j)&1)) add(id[find(calc(i,j))],id[find(calc(i+1,j+1))]);
		else add(id[find(calc(i+1,j))],id[find(calc(i,j+1))]);
	}
	ans=pls(ans,gao(tt-1));
	printf("%lld\n",ans);
	return 0;
}