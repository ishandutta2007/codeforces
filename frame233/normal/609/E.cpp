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

const int N=200005;
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],cnt;
int a[N],dep[N];
int fa[N][21],w[N][21];
ll res[N];
Finline void add(const int &u,const int &v,const int &w){c[++cnt]=(edge){v,front[u],w},front[u]=cnt;}
struct EDGE{
	int u,v,w,id;
	bool used;
	Finline bool operator < (const EDGE &o)const{return w<o.w;}
}e[N];
int pre[N];
int find(const int &x){return x==pre[x]?x:pre[x]=find(pre[x]);}
void dfs(int x,int Fa)
{
	dep[x]=dep[Fa]+1;
	fa[x][0]=Fa,w[x][0]=a[x];
	for(int i=1;i<=20;++i)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
		w[x][i]=max(w[x][i-1],w[fa[x][i-1]][i-1]);
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=Fa)
		{
			a[c[i].v]=c[i].w;
			dfs(c[i].v,x);
		}
	}
}
int Query(int x,int y)
{
	if(dep[x]<dep[y]) std::swap(x,y);
	int ans=0;
	for(int i=20;i>=0;--i)
	{
		if(dep[fa[x][i]]>=dep[y])
		{
			chmax(ans,w[x][i]);
			x=fa[x][i];
		}
	}
	if(x==y) return ans;
	for(int i=20;i>=0;--i)
	{
		if(fa[x][i]!=fa[y][i])
		{
			chmax(ans,max(w[x][i],w[y][i]));
			x=fa[x][i],y=fa[y][i];
		}
	}
	return max(ans,max(a[x],a[y]));
}
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=m;++i)
	{
		read(e[i].u,e[i].v,e[i].w);
		e[i].id=i;
	}
	std::sort(e+1,e+m+1);
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=n;++i) pre[i]=i;
	for(int i=1;i<=m&&cnt<n-1;++i)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			pre[find(e[i].u)]=find(e[i].v);
			e[i].used=1;
			ans+=e[i].w;
			++cnt;
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(e[i].used)
		{
			add(e[i].u,e[i].v,e[i].w);
			add(e[i].v,e[i].u,e[i].w);
		}
	}
	dfs(1,0);
	for(int i=1;i<=m;++i)
	{
		if(e[i].used)
		{
			res[e[i].id]=ans;
		}
		else
		{
			res[e[i].id]=ans+e[i].w-Query(e[i].u,e[i].v);
		}
	}
	for(int i=1;i<=m;++i) printf("%lld\n",res[i]);
	return 0;
}