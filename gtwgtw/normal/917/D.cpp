#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y) for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y) for(int i = (int)x; i >= (int)y; i --)
#define trace(x) cerr << #x << " " << x << endl;
#define dprintf(...) fprintf(stderr, __VA__ARGS__)
#define dln()        fprintf(stderr, "\n")
using namespace std;
typedef double db;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<PII> VPI;
typedef vector<long long> VL;
const	int N = 105;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e18;

inline int IN(){
	char ch = getchar(); int x = 0, f = 0;
	while(ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return f ? (-x) : x;
}

inline int Pow(int x, int y, int p){
	int an = 1;
	for(; y; y >>= 1, x = (LL)x * x % p) if(y & 1) an = (LL)an * x % p;
	return an;
}

void renew(int &x, int y){
	x += y;
	if(x < 0) x += P;
	else if(x >= P) x -= P;
}

void setIO(string a){
#ifndef LOCAL
	freopen((a + ".in").c_str(), "r", stdin);
	freopen((a + ".out").c_str(), "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

VI e[N];
int f[N][N][N],g[N][N],vis[N],sz[N],ans[N],n;

void dfs(int x)
{
	vis[x]=1;
	bool has=1;
	for(auto v:e[x])
	{
		if(vis[v]) continue;
		dfs(v);
		if(has)
		{
			has=0;
			sz[x]=sz[v];
			memcpy(f[x],f[v],sizeof f[v]);
		}else
		{
			REP(i,0,sz[x])
			REP(j,0,sz[x]) g[i][j]=f[x][i][j],f[x][i][j]=0;

			PER(i,sz[x],0)
			PER(j,sz[x],0)
			PER(a,sz[v],0)
			PER(b,sz[v],0)
			{
				f[x][i+a][j+b]=(f[x][i+a][j+b]+(LL)g[i][j]*f[v][a][b])%P;
			}

			sz[x]+=sz[v];
		}
	}
	if(x==1)
	{
		REP(i,0,sz[x])
		{
			REP(j,0,sz[x])
			{
				ans[i]=(ans[i]+(LL)f[x][i][j]*(j+1))%P;
			}
			ans[i]=(LL)ans[i]*Pow(n,i-1+P-1,P)%P;
		}
	}else
	if(!has){
		memcpy(g,f[x],sizeof g);
		memset(f[x],0,sizeof f[x]);
		REP(i,0,sz[x])
		REP(j,0,sz[x]){
			f[x][i][j+1]=(f[x][i][j+1]+g[i][j])%P;
			f[x][i+1][0]=(f[x][i+1][0]+(LL)g[i][j]*(j+1))%P;
		}
		sz[x]++;
	}
	if(has)
	{
		f[x][0][1]=1;
		f[x][1][0]=1;
		sz[x]=1;
		return;
	}
}

int C[N][N];

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d",&n);
	REP(i,1,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].pb(y);
		e[y].pb(x);
	}
	
	dfs(1);

	REP(i,0,n-1)
	{
		C[i][0]=1;
		REP(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	}

	REP(i,1,n-1)
		FOR(j,0,i) ans[i]=(ans[i]+(LL)(P-ans[j])*C[n-1-j][n-1-i])%P;

	PER(i,n-1,0) printf("%d\n",ans[i]);

	return 0;
}