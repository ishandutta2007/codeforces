// luogu-judger-enable-o2
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
const double eps=1e-8;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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

const int N=50005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
bool vis[N];
int siz[N];
int S,_max,root;
ll ans;
int res[N];
int a[N],pos;
int clr[N],_pos;
int k;
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
void getrt(const int &x,const int &fa)
{
	int maxx=0;
	siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v]&&c[i].v!=fa)
		{
			getrt(c[i].v,x);
			siz[x]+=siz[c[i].v];
			chmax(maxx,siz[c[i].v]);
		}
	}
	chmax(maxx,S-siz[x]);
	if(maxx<_max)
	{
		_max=maxx;
		root=x;
	}
}
void getdis(const int &x,const int &fa,const int &len)
{
	a[++pos]=len;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v]&&c[i].v!=fa)
		{
			getdis(c[i].v,x,len+1);
		}
	}
}
void solve(const int &x)
{
	_pos=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v])
		{
			pos=0;
			getdis(c[i].v,x,1);
			for(int j=1;j<=pos;++j)
			{
				if(a[j]<=k)
				{
					ans+=res[k-a[j]];
				}
			}
			for(int j=1;j<=pos;++j)
			{
				if(a[j]<=k)
				{
					++res[a[j]];
					clr[++_pos]=a[j];
				}
			}
		}
	}
	for(int i=1;i<=_pos;++i) res[clr[i]]=0;
}
void dfs(const int &x)
{
	vis[x]=true;
	solve(x);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v])
		{
			S=siz[c[i].v],_max=inf,root=0;
			getrt(c[i].v,x);
			dfs(root);
		}
	}
}
int main()
{
	res[0]=1;
	int n,x,y;
	read(n,k);
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	S=n,_max=inf,root=0;
	getrt(1,0);
	dfs(root);
	printf("%lld\n",ans);
    return 0;
}