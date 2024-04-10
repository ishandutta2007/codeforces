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
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
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

const int N=2005,mod=1000000007;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
struct node{
	int val,id;
	Finline bool operator < (const node &o)const
	{
		return val<o.val;
	}
}a[N];
int E[N][2];
int f[N];
void dfs(int x,int fa)
{
	f[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs(c[i].v,x);
			f[x]=1ll*f[x]*(f[c[i].v]+1)%mod;
		}
	}
}
int w[N];
bool used[N];
Finline void _add(ll &a,const ll &b){(a+=b)>=mod&&(a-=mod);}
int main()
{
	int d,n;
	read(d,n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].val);
		w[i]=a[i].val;
		a[i].id=i;
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<n;++i)
	{
		read(E[i][0],E[i][1]);
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		cnt=0;
		memset(front,0,sizeof(front));
		for(int j=1;j<n;++j)
		{
			if(!used[E[j][0]]&&!used[E[j][1]]&&w[E[j][0]]-a[i].val<=d&&w[E[j][1]]-a[i].val<=d)
			{
				add(E[j][0],E[j][1]);
				add(E[j][1],E[j][0]);
			}
		}
		dfs(a[i].id,0);
		_add(ans,f[a[i].id]);
		used[a[i].id]=1;
	}
	printf("%lld\n",ans);
    return 0;
}