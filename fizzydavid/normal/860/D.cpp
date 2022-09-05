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
int n,m;
int head[200111],nxt[400111],to[400111],tot=1;
int pe[200111];
bool vis[200111],vise[200111];
vector<pair<int,pair<int,int> > >v;
void dfs(int x,int pv=-1)
{
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int u=to[i];
		if(!vis[u])
		{
			pe[u]=i>>1;
			dfs(u,x);
		}
	}
	int pre=0,preid=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(vise[i>>1])continue;
		if((i>>1)==pe[x])continue;
		if(!pre)
		{
			pre=to[i];
			preid=i;
		}
		else
		{
			v.PB(MP(pre,MP(x,to[i])));
			vise[i>>1]=1;
			vise[preid>>1]=1;
			pre=preid=0;
		}
	}
	if(pe[x]&&pre)
	{
		v.PB(MP(pv,MP(x,pre)));
		vise[pe[x]]=1;
		vise[preid>>1]=1;
	}
}
int main()
{
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	putsi(v.size());
	for(int i=0;i<v.size();i++)
	{
		putsiii(v[i].FF,v[i].SS.FF,v[i].SS.SS);
	}
	return 0;
}