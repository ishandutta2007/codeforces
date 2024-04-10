//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
int tot=0;
int ti[1000000],tj[1000000],tk[1000000];
vector<int> pv[1000000];
struct value
{
	int v;
	int id;
	void update(value a)
	{
		if(a.v<v)
		{
			v=a.v;
			pv[id].clear();
			pv[id].PB(a.id);
		}
	}
	void update(value a,value b)
	{
		if(a.v+b.v<v)
		{
			v=a.v+b.v;
			pv[id].clear();
			pv[id].PB(a.id);
			pv[id].PB(b.id);
		}
	}
};
value newv(int i=-1,int j=-1,int k=-1)
{
	value ret;
	ret.id=++tot;
	ret.v=1<<29;
	ti[tot]=i;tj[tot]=j;tk[tot]=k;
	return ret;
}
#define UP 0
#define DOWN 1
#define TUP 2
int n,m;
int cd[233];
vector<int> con[233];
value dp[233][233][3];
void dfs(int x,int pre=-1)
{
	for(int i=0;i<=n+2;i++)
	{
		dp[x][i][UP]=newv(x,i,UP);
		dp[x][i][DOWN]=newv(x,i,DOWN);
	}
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		dfs(u,x);
	}
	for(int d=1;d<=n;d++)
	{
		value wu0=newv();
		value wu1=newv();
		value wd=newv();
		wu0.v=cd[d];
		wu1.v=1<<28;
		wd.v=cd[d];
		for(int i=0;i<con[x].size();i++)
		{
			int u=con[x][i];
			if(u==pre)continue;
			value nwd=newv();
			nwd.update(wd,dp[u][d+1][DOWN]);
			nwd.update(wd,dp[u][d][UP]);
//			wd+=min(dp[u][d][UP],dp[u][d+1][DOWN]);
			value nwu1=newv();
			value tmp=newv();
			tmp.update(wu0,dp[u][d-1][UP]);
			tmp.update(wu1,dp[u][d-1][UP]);
			value tmp2=newv();
			tmp2.update(dp[u][d+1][DOWN]);
			tmp2.update(dp[u][d][UP]);
			nwu1.update(wu1,tmp2);
			nwu1.update(tmp);
			value nwu0=newv();
			nwu0.update(wu0,tmp2);
//			wu1=min(wu1+min(dp[u][d+1][DOWN],dp[u][d][UP]),min(wu0,wu1)+dp[u][d-1][UP]);
//			wu0+=min(dp[u][d+1][DOWN],dp[u][d][UP]);
			swap(wu0,nwu0);
			swap(wu1,nwu1);
			swap(wd,nwd);
		}
		dp[x][d][UP].update(wu1);
		dp[x][d][DOWN].update(wd);
//		dp[x][d][UP]=wu1;
//		dp[x][d][DOWN]=wd;
	}
	dp[x][0][UP].v=cd[0];
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		value nv=newv();
		nv.update(dp[x][0][UP],dp[u][1][DOWN]);
		nv.update(dp[x][0][UP],dp[u][0][UP]);
		swap(nv,dp[x][0][UP]);
	}
	for(int i=n;i>=0;i--)
	{
		dp[x][i][DOWN].update(dp[x][i][UP]);
	}
/*	cerr<<"x="<<x<<endl;
	for(int i=0;i<=n;i++)cerr<<dp[x][i][UP]<<" ";cerr<<endl;
	for(int i=0;i<=n;i++)cerr<<dp[x][i][DOWN]<<" ";cerr<<endl;*/
}
bool vis[1000000];
bool center[233];
void findans(int x)
{
//	cerr<<"findans:"<<x<<" "<<ti[x]<<" "<<tj[x]<<" "<<tk[x]<<endl;
	vis[x]=1;
	for(int i=0;i<pv[x].size();i++)
	{
		if(!vis[pv[x][i]])
		{
			findans(pv[x][i]);
		}
	}
	if(tj[x]==0)
	{
		center[ti[x]]=1;
	}
}
int q[233],qn;
int g[233];
int main()
{
	getii(n,cd[0]);
	for(int i=1;i<n;i++)geti(cd[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs(1);
	int mn=mod,mnid=0;
	for(int i=0;i<=n;i++)
	{
		if(dp[1][i][UP].v<mn)
		{
			mn=dp[1][i][UP].v;
			mnid=i;
		}
	}
	cout<<mn<<endl;
	findans(dp[1][mnid][UP].id);
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		if(center[i])
		{
			q[qn++]=i;
			g[i]=i;
			vis[i]=1;
		}
	}
	for(int i=0;i<qn;i++)
	{
		int u=q[i];
		for(int j=0;j<con[u].size();j++)
		{
			int v=con[u][j];
			if(!vis[v])
			{
				vis[v]=1;
				g[v]=g[u];
				q[qn++]=v;
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<g[i]<<" ";cout<<endl;
	return 0;
}