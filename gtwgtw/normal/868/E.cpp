#include <set>
#include <map>
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
typedef long long LL;
typedef long double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPI;
const	int N = 55;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e15;

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
#else
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

VI e[N];
int R[N];
int d[N][N],st,x[N],xtot;

int dfs(int x,int y){
	int ans=::x[x];
	for(auto v : e[x]) if(v != y) ans += dfs(v,x);
	return ans;
}

bool vis[N][N][N][N];
int ff[N][N][N][N];
int n;

int tmp[N];
void dp(int u,int pa,int tot,int now){
	if(vis[u][pa][tot][now])return;
	vis[u][pa][tot][now]=1;
	if(R[u]==1){
		assert(now);
		if(tot-now==0){	
			ff[u][pa][tot][now]=0;
			return;
		}
		dp(pa,u,tot-now,tot-now);
		ff[u][pa][tot][now]=d[u][pa]+ff[pa][u][tot-now][tot-now];
		return;
	}
	int rdp[N];
	memset(rdp,0,sizeof rdp);
	rdp[0]=1e9;
	for(auto v:e[u])if(v^pa){
		REP(xnow,1,tot) dp(v,u,tot,xnow);
		memcpy(tmp,rdp,sizeof tmp);
		REP(xpre,0,tot) REP(xnow,1,tot-xpre){
			rdp[xpre+xnow]=max(rdp[xpre+xnow],min(tmp[xpre],d[u][v]+ff[v][u][tot][xnow]));
		}
	}
	ff[u][pa][tot][now]=rdp[now];
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d",&n);
	FOR(i,1,n){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(v);
		e[v].pb(u);
		d[u][v]=d[v][u]=w;
		R[u]++;R[v]++;
	}

	scanf("%d",&st);
	scanf("%d",&xtot);
	REP(i,1,xtot){
		int p=IN();
		x[p]++;
	}

	int ans=1<<30;
	for(auto v : e[st]){
		int sz=dfs(v,st);
		if(sz){
			dp(v,st,xtot,sz);
			chkmin(ans,ff[v][st][xtot][sz]+d[v][st]);
		}
	}

	printf("%d\n",ans); 

	return 0;
}