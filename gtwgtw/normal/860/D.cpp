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
const	int N = 300005;
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

int ux[N], vx[N], n, m;
struct edge{
	int v, id, pre;
}e[N * 2]; int dex, adj[N];
int gtw[N], deg[N], vis[N];

void dfs(int x, int par){
	vis[x] = 1;
	for(int i = adj[x]; i; i = e[i].pre){
		int v = e[i].v;
		if(vis[v]) continue;
		dfs(v, x);
		if(deg[v]){
			int id = e[i].id;
			deg[v] ^= 1;
			deg[x] ^= 1;
			gtw[id] ^= 1;
		}
	}
}

VI bel[N];

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif
	
	scanf("%d%d", &n, &m);

	REP(i, 1, m){
		scanf("%d%d", ux + i, vx + i);
		e[++dex] = (edge){vx[i], i, adj[ux[i]]}; adj[ux[i]] = dex;
		e[++dex] = (edge){ux[i], i, adj[vx[i]]}; adj[vx[i]] = dex;
		gtw[i] = 0;
		deg[ux[i]] ^= 1;
	}

	REP(i, 1, n) if(!vis[i]) dfs(i, 0);
	int ans = m;
	REP(i, 1, n) if(deg[i]) ans --;
	ans /= 2;
	printf("%d\n", ans);

	REP(i, 1, m){
		if(!gtw[i]) bel[ux[i]].pb(vx[i]);
		else bel[vx[i]].pb(ux[i]);
	}

	REP(i, 1, n){
//		printf("%d\n", bel[i].size()); 
		for(int j = 0; j + 1 < bel[i].size(); j += 2){
			int u = bel[i][j];
			int v = bel[i][j + 1];
			printf("%d %d %d\n", u, i, v);
		}
	}


	return 0;
}