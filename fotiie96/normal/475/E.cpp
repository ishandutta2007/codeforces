#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) cout<<"Case #"<<++__<<": "<<x<<endl 
#define POP(x) (__builtin_popcount(x))
#define POPL(x) (__builtin_popcountll(x))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=2010;
int dfn[N],low[N],vis[N],sta[N],bel[N],ps[N],sz[N];
int g[N][N],G[N][N];
VI son[N];
int ans,n,m,tot,top,u,v,bs;
void dfss(int u,int f) {
	dfn[u]=low[u]=++tot;
	vis[u]=1; sta[top++]=u;
	rep(v,1,n+1) if (g[u][v]) {
		if (v==f) continue;
		if (!vis[v]) dfss(v,u);
		low[u]=min(low[u],low[v]);
	}
	if (dfn[u]==low[u]) {
		++m;
		while (1) {
			bel[sta[top-1]]=m;
			ps[m]++;
			if (sta[--top]==u) break;
		}
	}
}
int ddfs(int u) {
	int ret=ps[u]; vis[u]=1;
	rep(v,1,m+1) if (G[u][v]&&!vis[v]) ret+=ddfs(v);
	return ret;
}
inline int C(int n) { return n*(n-1)/2;}
void gao(VI &c,int sm) {
	bitset<2010> dp;
	dp[0]=1;
	rep(i,0,SZ(c)) dp|=(dp<<c[i]),ans+=C(c[i]);
	int s=sm/2;
	per(i,0,s+1) if (dp[i]) {
		ans-=C(i)+C(sm-i);
		return;
	}
}
void dfs(int u,int f) {
	sz[u]=ps[u];
	bs+=ps[u]*ps[u];
	rep(v,1,m+1) if (G[u][v]&&v!=f) {
		dfs(v,u);
		sz[u]+=sz[v];
		son[u].pb(sz[v]);
	}
	son[u].pb(n-sz[u]);
	gao(son[u],n-ps[u]);
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	m=0;
	rep(i,1,n+1) if (!vis[i]) dfss(i,0);
	rep(i,1,n+1) rep(j,1,n+1) if (bel[i]!=bel[j]&&g[i][j]) G[bel[i]][bel[j]]=1;
	memset(vis,0,sizeof(vis));
	rep(i,1,m+1) if (!vis[i]) {
		n=ddfs(i);
		bs+=n*n;
		dfs(i,0);
	}
	printf("%d\n",ans+bs/2);
}