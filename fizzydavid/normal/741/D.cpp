//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n;
int p[500111],msk[500111],tab[1<<22];
int dfn[500111],dfnr[500111],dfntot;
int a[500111],sz[500111],mxs[500111],lv[500111];
vector<int>con[500111];
void dfs(int x)
{
	dfn[x]=++dfntot;
	a[dfntot]=x;
	if(mxs[x])
	{
		msk[mxs[x]]^=msk[x];
		lv[mxs[x]]=lv[x]+1;
		dfs(mxs[x]);
	}
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i]==mxs[x])continue;
		msk[con[x][i]]^=msk[x];
		lv[con[x][i]]=lv[x]+1;
		dfs(con[x][i]);
	}
	dfnr[x]=dfntot;
}
int ans[500111];
void solve(int x,bool keep=0)
{
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i]==mxs[x])continue;
		solve(con[x][i]);
		ans[x]=max(ans[x],ans[con[x][i]]);
	}
	if(mxs[x])
	{
		solve(mxs[x],1);
		ans[x]=max(ans[x],ans[mxs[x]]);
		for(int i=0;i<con[x].size();i++)
		{
			int u=con[x][i];
			if(u==mxs[x])continue;
			for(int j=dfn[u];j<=dfnr[u];j++)
			{
				ans[x]=max(ans[x],lv[a[j]]-2*lv[x]+tab[msk[a[j]]]);
				for(int k=0;k<22;k++)ans[x]=max(ans[x],lv[a[j]]-2*lv[x]+tab[msk[a[j]]^(1<<k)]);
			}
			for(int j=dfn[u];j<=dfnr[u];j++)tab[msk[a[j]]]=max(tab[msk[a[j]]],lv[a[j]]);
		}
		ans[x]=max(ans[x],tab[msk[x]]-lv[x]);
		for(int k=0;k<22;k++)ans[x]=max(ans[x],tab[msk[x]^(1<<k)]-lv[x]);
	}
	if(!keep)for(int j=dfn[x];j<=dfnr[x];j++)tab[msk[a[j]]]=-n;
	else tab[msk[x]]=max(tab[msk[x]],lv[x]);
}
int main()
{
	geti(n);
	for(int i=2;i<=n;i++)
	{
		geti(p[i]);
		char c=mygetchar();
		msk[i]=1<<(c-'a');
		con[p[i]].push_back(i);
	}
	for(int i=0;i<(1<<22);i++)tab[i]=-n;
	for(int i=n;i>=1;i--)
	{
		sz[i]++;
		if(i>1)sz[p[i]]+=sz[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<con[i].size();j++)
		{
			if(sz[con[i][j]]>sz[mxs[i]])
			{
				mxs[i]=con[i][j];
			}
		}
	}
	dfs(1);
	solve(1);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}