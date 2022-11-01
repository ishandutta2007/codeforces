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
const	int N = 500005;
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

int sz[N];
int n, rt, tot, seq[N << 1];
int dep[N], id[N], dfn[N], tim;
int gfa[N], stk[N], ed[N];
int Fa[20][N], *fa = Fa[0];
LL dp[N];
LL f[N];
VI e[N];

void dfs(int x){
	dfn[x] = ++tim;
	dep[x] = dep[fa[x]] + 1;
	for(int v : e[x]) dfs(v);
	ed[x] = tim;
}

int cmp(const int &a, const int &b){
	return dep[a] < dep[b];
}

int cmpdfn(const int &a, const int &b){
	return dfn[a] < dfn[b];
}


int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	PER(i, 19, 0) if(dep[Fa[i][x]] >= dep[y]) x = Fa[i][x];
	PER(i, 19, 0) if(Fa[i][x] ^ Fa[i][y]) x = Fa[i][x], y = Fa[i][y];
	return (x == y) ? x : fa[x];
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d", &n);
	REP(i, 1, n){
		fa[i] = IN();
		if(fa[i]){
			int u = fa[i], v = i;
			e[u].pb(v);
		}
	}
	REP(i, 1, n) if(!fa[i]) rt = i;

	REP(i, 1, 19) REP(j, 1, n) Fa[i][j] = Fa[i - 1][Fa[i - 1][j]];
	
	dfs(rt);

	REP(i, 1, n) id[i] = i;
	sort(id + 1, id + n + 1, cmp);

	f[rt] = 1;
	REP(i, 2, n){
		int j = i;
		while(j <= n && dep[id[j]] == dep[id[i]]) ++ j; -- j;
		REP(k, i, j){
			int u = id[k];
			f[u] = f[fa[u]];
		}

		int nowdep = dep[id[i]];

		tot = 0;
		REP(k, i, j) seq[++tot] = id[k];
		sort(seq + 1, seq + tot + 1, cmpdfn);
		int gtot = tot;
		FOR(i, 1, gtot) seq[++tot] = lca(seq[i], seq[i + 1]);
		sort(seq + 1, seq + tot + 1, cmpdfn);
		tot = unique(seq + 1, seq + tot + 1) - (seq + 1);
		REP(i, 1, tot) gfa[seq[i]] = 0;
		int top = 0;
		REP(i, 1, tot){
			int u = seq[i];
			while(top && ed[stk[top]] < dfn[u]) top --;
			gfa[u] = stk[top];
			stk[++top] = u;
		}
		REP(i, 1, tot) if(dep[seq[i]] == nowdep) sz[seq[i]] = 1; else sz[seq[i]] = 0;
		PER(i, tot, 1){
			int u = seq[i];
			if(gfa[u]) sz[gfa[u]] += sz[u];
		}
		REP(i, 1, tot){
			int u = seq[i];
			if(gfa[u]){
				dp[u] = dp[gfa[u]] + 1LL * dep[gfa[u]] * (sz[gfa[u]] - sz[u]);
			}else dp[u] = 0;
		}

		REP(i, 1, tot) if(dep[seq[i]] == nowdep) f[seq[i]] += dp[seq[i]] + dep[seq[i]];

		i = j;
	}

	REP(i, 1, n) printf("%lld ", f[i] - dep[i]); puts("");
	

	return 0;
}