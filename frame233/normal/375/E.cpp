// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=505;
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v,int w){c[++edge_cnt]=(edge){v,front[u],w},front[u]=edge_cnt;}
short dp[N][N][N],minn[N][N],f[N][N];
std::vector<int> nd[N];
int cur;
void dfs1(int x,int fa,int L)
{
	if(L<0) return;
	nd[cur].pb(x);
	for(int i=front[x];i;i=c[i].nxt) if(c[i].v!=fa) dfs1(c[i].v,x,L-c[i].w);
}
int siz[N],col[N],dfn[N],id;
void dfs2(int x,int fa)
{
	dp[x][1][x]=!col[x],siz[x]=1,dfn[x]=++id;
	for(auto it:nd[x])if(it!=x)dp[x][0][it]=0;
	for(int _=front[x];_;_=c[_].nxt)
	{
		int v=c[_].v;
		if(v==fa) continue;
		dfs2(v,x);
		std::vector<int> qwq;
		for(auto it:nd[x])if(dfn[it]<dfn[v]||dfn[it]>=dfn[v]+siz[v])qwq.pb(it);
		for(int i=0;i<=siz[x]+siz[v];++i) memset(f[i],63,sizeof(f[i]));
		for(int i=0;i<=siz[x];++i)for(int j=0;j<=siz[v];++j)
		{
			for(auto k:nd[x]) chmin(f[i+j][k],(short)(dp[x][i][k]+dp[v][j][k]));
			for(auto k:qwq) chmin(f[i+j][k],(short)(dp[x][i][k]+minn[v][j]));
		}
		for(int i=0;i<=siz[x]+siz[v];++i) memcpy(dp[x][i],f[i],sizeof(f[i]));
		siz[x]+=siz[v];
	}
	for(int i=0;i<=siz[x];++i)
	{
		minn[x][i]=(1<<13);
		for(auto it:nd[x])if(dfn[it]>=dfn[x]&&dfn[it]<dfn[x]+siz[x])chmin(minn[x][i],dp[x][i][it]);
	}
}
int main()
{
	memset(dp,63,sizeof(dp));
	int n,L;read(n,L);
	int x,y,z;
	for(int i=1;i<=n;++i) read(col[i]);
	for(int i=1;i<n;++i) read(x,y,z),addedge(x,y,z),addedge(y,x,z);
	for(int i=1;i<=n;++i) cur=i,dfs1(i,0,L);
	dfs2(1,0);
	int ans=minn[1][std::accumulate(col+1,col+n+1,0)];
	printf("%d\n",ans>n?-1:ans);
	return 0;
}