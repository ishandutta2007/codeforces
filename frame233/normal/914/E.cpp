// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],_cnt;
Finline void add(int u,int v)
{
	c[++_cnt]=(edge){v,front[u]},front[u]=_cnt;
}
int a[N];
bool vis[N];
int S,sum,_maxx,root;
int siz[N];
void getrt(int x,int fa)
{
	int maxx=0;
	siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&!vis[c[i].v])
		{
			getrt(c[i].v,x);
			siz[x]+=siz[c[i].v];
			chmax(maxx,siz[c[i].v]);
		}
	}
	chmax(maxx,S-siz[x]);
	if(maxx<_maxx)
	{
		_maxx=maxx;
		root=x;
	}
}
int getsize(int x,int fa)
{
	int siz=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&!vis[c[i].v])
		{
			siz+=getsize(c[i].v,x);
		}
	}
	return siz;
}
struct node{
	int nd,val;
}t[N];
int pos;
void getdis(int x,int fa,int st)
{
	st^=1<<a[x];
	t[++pos]=(node){x,st};
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&!vis[c[i].v])
		{
			getdis(c[i].v,x,st);
		}
	}
}
ll ans[N];
ll qwq[N];
void dfs1(int x,int fa)
{
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&!vis[c[i].v])
		{
			dfs1(c[i].v,x);
			qwq[x]+=qwq[c[i].v];
		}
	}
	ans[x]+=qwq[x];
}
node cl[N];
int _pos;
int cnt[(1<<20)+1];
void solve(int x)
{
	cnt[0]=1;
	_pos=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v])
		{
			pos=0;
			getdis(c[i].v,x,0);
			for(int j=1;j<=pos;++j)
			{
				++cnt[t[j].val];
				cl[++_pos]=t[j];
			}
		}
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v])
		{
			pos=0;
			getdis(c[i].v,x,0);
			for(int j=1;j<=pos;++j)
			{
				--cnt[t[j].val];
			}
			for(int j=1;j<=pos;++j)
			{
				t[j].val^=1<<a[x];
				qwq[t[j].nd]+=cnt[t[j].val];
				for(int k=0;k<20;++k)
				{
					qwq[t[j].nd]+=cnt[t[j].val^(1<<k)];
				}
			}
			for(int j=1;j<=pos;++j)
			{
				++cnt[t[j].val^(1<<a[x])];
			}
		}
	}
	--cnt[0];
	int cur=1<<a[x];
	ll tmp=cnt[cur];
	for(int i=0;i<20;++i) tmp+=cnt[cur^(1<<i)];
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v])
		{
			dfs1(c[i].v,x);
			tmp+=qwq[c[i].v];
		}
	}
	ans[x]+=tmp>>1;
	while(_pos)
	{
		cnt[cl[_pos].val]=0;
		qwq[cl[_pos].nd]=0;
		--_pos;
	}
}
void dfs(int x)
{
	vis[x]=true;
	solve(x);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v])
		{
			S=getsize(c[i].v,x);
			_maxx=inf;
			root=0;
			getrt(c[i].v,x);
			dfs(root);
		}
	}
}
int main()
{
	int n;
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	char ch;
	for(int i=1;i<=n;++i)
	{
		ch=getchar();
		while(ch<97||ch>116) ch=getchar();
		a[i]=ch-97;
	}
	S=n,_maxx=inf,root=0;
	getrt(1,0);
	dfs(root);
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]+1);
	printf("\n");
	return 0;
}