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
vector<PII> e[N];
int d[N][N],pre[N],mind[N],vis[N],n;
ll g[N][N];
void add(int u,int v,int w) {
	e[u].pb(mp(v,w)); e[v].pb(mp(u,w));
}
void dfs(int u,int f,ll dep,int rt) {
	g[rt][u]=dep;
	rep(j,0,SZ(e[u])) {
		int v=e[u][j].fi;
		if (v==f) continue;
		dfs(v,u,dep+e[u][j].se,rt);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) rep(j,0,n) scanf("%d",&d[i][j]);
	rep(i,0,n) if (d[i][i]!=0) { puts("NO"); return 0;}
	rep(i,0,n) rep(j,0,n) if (d[i][j]!=d[j][i]) { puts("NO"); return 0; }
	rep(i,0,n) rep(j,0,n) if (i!=j&&d[i][j]==0) { puts("NO"); return 0; }
	rep(i,0,n) vis[i]=0;
	rep(i,0,n) mind[i]=d[0][i],pre[i]=0;
	vis[0]=1;
	rep(i,0,n-1) {
		int md=1<<30,p=0;
		rep(j,0,n) if (vis[j]==0&&mind[j]<md) {
			md=mind[j]; p=j;
		}
		add(p,pre[p],mind[p]);
		vis[p]=1;
		rep(j,0,n) if (vis[j]==0&&mind[j]>d[p][j]) {
			mind[j]=d[p][j]; pre[j]=p;
		}
	}
	rep(i,0,n) dfs(i,-1,0,i);
	rep(i,0,n) rep(j,0,n) if (g[i][j]!=d[i][j]) {
		puts("NO");
		return 0;
	}
	puts("YES");
}