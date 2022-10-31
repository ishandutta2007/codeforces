// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
Finline ll C(int n,int m)
{
	return !m?1:m==1?n:m==2?(1ll*n*(n-1)>>1):(1ll*n*(n-1)*(n-2)/6);
}
int fa[N],Fa[N],siz[N],ssiz[N],n,dep[N];
ll val[N],ans;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	Fa[x]=fa,siz[x]=1,ssiz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		dfs(v,x);
		val[x]+=C(ssiz[v],2);
		ssiz[x]+=ssiz[v];
	}
	val[x]+=C(n-ssiz[x],2);
}
void merge(int x,int y)
{
	ans-=6ll*(C(siz[x],3)+C(siz[y],3));
	ans-=4ll*(C(siz[x],2)*(n-siz[x])+C(siz[y],2)*(n-siz[y]));
	ans-=2ll*((ll)siz[x]*(C(n-siz[x],2)-val[x])+(ll)siz[y]*(C(n-siz[y],2)-val[y]));
	
	fa[x]=y,siz[y]+=siz[x];
	val[y]+=val[x],val[y]-=C(n-ssiz[x],2)+C(n-ssiz[y],2);
	val[y]-=C(ssiz[x],2);
	val[y]+=C(n-ssiz[y],2);
	
	ans+=6ll*C(siz[y],3);
	ans+=4ll*C(siz[y],2)*(n-siz[y]);
	ans+=2ll*siz[y]*(C(n-siz[y],2)-val[y]);
}
int main()
{
	read(n);int x,y;
	for(int i=1;i<n;++i) read(x,y),addedge(x,y),addedge(y,x);
	dfs(1,0);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=n;++i) ans+=2ll*(C(n-1,2)-val[i]);
	printf("%lld\n",ans);
	int _;read(_);
	while(_--)
	{
		read(x,y);
		while(find(x)!=find(y))
		{
			x=find(x),y=find(y);
			if(dep[x]<dep[y]) std::swap(x,y);
			if(x!=find(Fa[x])) merge(x,find(Fa[x]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}