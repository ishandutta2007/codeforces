// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
struct edge{
	int v,nxt;
	ll w;
}c[N];
int front[N],cnt;
Finline void add(const int &u,const int &v,const ll &w){c[++cnt]=(edge){v,front[u],w},front[u]=cnt;}
ll a[N],b[N];
double f[N];
void dfs(int x)
{
	f[x]=b[x]-a[x];
	for(int i=front[x];i;i=c[i].nxt)
	{
		dfs(c[i].v);
		if(f[c[i].v]<0)
		{
			f[x]+=f[c[i].v]*(double)c[i].w;
		}
		else
		{
			f[x]+=f[c[i].v];
		}
	}
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(b[i]);
	for(int i=1;i<=n;++i) read(a[i]);
	int x;
	ll y;
	for(int i=2;i<=n;++i)
	{
		read(x,y);
		add(x,i,y);
	}
	dfs(1);
	if(f[1]>=0.0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}