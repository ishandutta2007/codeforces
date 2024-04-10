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
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n,rt;
vector<int>con[200111];
int sz[200111];
vector<int>key;
void dfs(int x,int pre=-1)
{
	sz[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i]==pre)continue;
		dfs(con[x][i],x);
		sz[x]+=sz[con[x][i]];
	}
}
vector<pair<int,pair<int,int> > >cmd;
int last,curkey;
void dfs2(int x,int pre)
{
	if(pre!=rt)
	{
		cmd.PB(MP(rt,MP(last,x)));
		cmd.PB(MP(x,MP(pre,curkey)));
		last=x;
	}
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i]==pre)continue;
		dfs2(con[x][i],x);
	}
}
void solve(int u,int v=-1)
{
	rt=u;
	for(int i=0;i<con[u].size();i++)
	{
		if(con[u][i]==v)continue;
		last=con[u][i];
		curkey=con[u][i];
		dfs2(con[u][i],u);
		cmd.PB(MP(rt,MP(last,curkey)));
	}
}
int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs(1);
	int u=1,v=-1;
	for(int i=1;i<=n;i++)
	{
		if(sz[i]*2>=n&&sz[i]<sz[u])
		{
			u=i;
		}
	}
	dfs(u);
	for(int i=0;i<con[u].size();i++)
	{
		if(sz[con[u][i]]*2==n)
		{
			v=con[u][i];
		}
	}
//	cerr<<u<<" "<<v<<endl;
	if(v==-1)
	{
		solve(u);
	}
	else
	{
		solve(u,v);
		solve(v,u);
	}
	putsi(cmd.size());
	for(int i=0;i<cmd.size();i++)putsiii(cmd[i].FF,cmd[i].SS.FF,cmd[i].SS.SS);
	return 0;
}