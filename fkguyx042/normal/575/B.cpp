#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define CH (ch=getchar())
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,V)     for(__typeof(*V.begin()) i:  V)
#define For(i,a,b)   for(int i=(int)a;i<=(int)b;i++)
#define Rep(i,a,b)   for(int i=(int)a;i< (int)b;i++)
#define Forn(i,a,b)  for(int i=(int)a;i>=(int)b;i--)
#define pend(x)      ((x)=='\n'||(x)=='\r'||(x)=='\t'||(x)==' ')
using namespace std;
typedef	double		db;
typedef	long long	ll;
const	int	N=200005;
const	int mo=1000000007;
const	int inf=(int)1e9;

inline int IN(){
	char ch;CH; int f=0,x=0;
	for(;pend(ch);CH); if(ch=='-')f=1,CH;
	for(;!pend(ch);CH) x=x*10+ch-'0';
	return (f)?(-x):(x);
}

int Pow(int x,int y,int p){
	int A=1;
	for(;y;y>>=1,x=(ll)x*x%p) if(y&1) A=(ll)A*x%p;
	return A;
}

int sum[N*10],p[N*10];
int n,fa[20][N],dep[N],tsub[N],trt[N];
struct edge{
	int u,v,w,pre;
}e[N];int dex,adj[N];

void dfs(int x){
	for(int i=adj[x];i;i=e[i].pre){
		int v=e[i].v;
		if(v==fa[0][x])continue;
		fa[0][v]=x;
		dep[v]=dep[x]+1;
		For(i,1,17) fa[i][v]=fa[i-1][fa[i-1][v]];
		dfs(v);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	Forn(i,17,0) if(dep[fa[i][x]]>=dep[y]) x=fa[i][x];
	Forn(i,17,0) if(fa[i][x]^fa[i][y]) x=fa[i][x],y=fa[i][y];
	return (x==y)?(x):(fa[0][x]);
}

void Dfs(int x){
	for(int i=adj[x];i;i=e[i].pre){
		int v=e[i].v;
		if(v==fa[0][x])continue;
		Dfs(v);
		trt[x]+=trt[v];
		tsub[x]+=tsub[v];
	}
}

int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x=IN(),y=IN(),w=IN();
		e[++dex]=(edge){x,y,w,adj[x]};adj[x]=dex;
		e[++dex]=(edge){y,x,3-w,adj[y]};adj[y]=dex;
	}
	dfs(dep[1]=1);
	int K=IN(),Pre=1;
	For(i,1,K){
		int x=IN();
		int Lca=lca(Pre,x);
		trt[Pre]++;
		trt[Lca]--;
		tsub[x]++;
		tsub[Lca]--;
		Pre=x;
	}
	Dfs(1);
	int ans=0;
	p[1]=1;
	For(i,2,K) p[i]=(p[i-1]+p[i-1])%mo;
	For(i,1,K) sum[i]=(sum[i-1]+p[i])%mo;
	For(i,1,dex){
		int u=e[i].u,v=e[i].v;
		if(u==fa[0][v])continue;
		//u son,v fir
		if(e[i].w==0||e[i].w==3)continue;
		if(e[i].w==2){
			ans+=sum[trt[u]];
		}else ans+=sum[tsub[u]];
		ans%=mo;
	}
	printf("%d\n",ans);
	return 0;
}