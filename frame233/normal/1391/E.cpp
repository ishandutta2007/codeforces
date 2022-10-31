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

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=500005;
struct edge{
	int v,nxt;
}c[N<<2];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
std::vector<int> v[N];
int dep[N],Fa[N];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1,Fa[x]=fa;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(!dep[v]) dfs(v,x);
	}
}
void MAIN()
{
	edge_cnt=0;
	int n,m;read(n,m);
	memset(front,0,(n+3)<<2);
	memset(dep,0,(n+3)<<2);
	int x,y;
	for(int i=1;i<=m;++i) read(x,y),addedge(x,y),addedge(y,x);
	dfs(1,0);
	for(int i=1;i<=n;++i)
	{
		if(dep[i]>=(n+1)>>1)
		{
			int cur=i;
			printf("PATH\n%d\n",dep[i]);
			while(cur)
			{
				printf("%d ",cur);
				cur=Fa[cur];
			}
			return;
		}
	}
	for(int i=1;i<=n;++i) v[i].clear();
	for(int i=1;i<=n;++i) v[dep[i]].pb(i);
	std::vector<pi> ans;
	for(int i=1;i<=n;++i) for(int j=0;j+1<SZ(v[i]);j+=2) ans.pb(mkpr(v[i][j],v[i][j+1]));
	printf("PAIRING\n%d\n",SZ(ans));
	for(auto it:ans) printf("%d %d\n",it.first,it.second);
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}