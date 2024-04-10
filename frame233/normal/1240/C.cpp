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

const int N=500005;
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],cnt;
ll f[N][2];
Finline void add(const int &u,const int &v,const int &w)
{
	c[++cnt]=(edge){v,front[u],w},front[u]=cnt;
}
int k;
void dfs(int x,int fa)
{
	f[x][0]=0;
	std::vector<int> v;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			f[c[i].v][1]=c[i].w;
			dfs(c[i].v,x);
			f[x][0]+=f[c[i].v][0];
			f[x][1]+=f[c[i].v][0];
			v.emplace_back(f[c[i].v][1]-f[c[i].v][0]);
		}
	}
	std::sort(v.begin(),v.end());
	std::reverse(v.begin(),v.end());
	int cnt=0;
	for(auto it:v)
	{
		++cnt;
		if(it<0) break;
		f[x][0]+=it;
		if(cnt!=k) f[x][1]+=it;
		if(cnt==k) break;
	}
}
void MAIN()
{
	cnt=0;
	int n;
	read(n,k);
	memset(front,0,4*(n+3));
	int x,y,z;
	for(int i=1;i<n;++i)
	{
		read(x,y,z);
		add(x,y,z),add(y,x,z);
	}
	f[1][1]=0;
	dfs(1,0);
	printf("%lld\n",f[1][0]);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}