#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, int> pli;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

template<typename T> bool chmin(T &a, const T &b)
	{ return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b)
	{ return a < b ? a = b, true : false; }

const int maxN = 100000;
const int maxM = 100000;
const LL FINITE = 314000000;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
vector<int> deg[maxN]; /*degreeArchive[maxN],*/
vector<LL> val[maxN];
vector< vector<int> > G[maxN];
vector<pii> T[maxN];

LL f[maxN], g[maxN];


// bool stoppable[maxN];
/*void toposortStoppable() {
	queue<int> Q;
	for(int u = 1; u <= n; ++u) stoppable[u] = false;
	stoppable[0] = true; Q.push(0);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(pii p : T[u]) {
			if(--deg[p.first][p.second] == 0 && !stoppable[p.first]) {
				stoppable[p.first] = true;
				Q.push(p.first);
			}
		}
	}
}*/

bool canInf[maxN];

const int NOT = 0;
const int ED = -1;
const int ING = 1;
int status[maxN];
void DFS(int u) {
	status[u] = ING;
	for(auto &l : G[u]) {
		bool tmp = false;
		for(int &v : l) {
			if(f[v] == -1) goto FAIL;
			switch (status[v]) {
				case NOT:
					DFS(v);
				case ED:
					tmp = tmp || canInf[v];
					break;
				case ING:
					tmp = true;
					break;
			}
		}
		canInf[u] = canInf[u] || tmp;
		FAIL : {}
	}
	status[u] = ED;
}


/*void copyDegree() {
	for(int u = 1; u <= n; ++u) {
		for(auto i = deg[u].begin(), j = degreeArchive[u].begin();
			i != deg[u].end() && j != degreeArchive[u].end(); ++i, ++j)
			*i = *j;
	}
}*/

priority_queue < pli, vector<pli>, std::greater<pli> > pq;
bool vis[maxN];
void Dijkstra() {
	for(int u = 0; u <= n; ++u) vis[u] = false, f[u] = INF;
	pq.push(pli(1, 0)); f[0] = 1;
	while(!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if(vis[u]) continue; else vis[u] = true;
		for(auto &p : T[u]) {
			val[p.first][p.second] += f[u];
			if(--deg[p.first][p.second] == 0 && (f[p.first] > val[p.first][p.second])) {
				f[p.first] = val[p.first][p.second];
				chmin(f[p.first], FINITE);
				pq.push(pli(f[p.first], p.first));
			}
		}
	}
	for(int u = 1; u <= n; ++u) if(f[u] == INF) f[u] = g[u] = -1;
}

void initialize() {
	scanf("%d%d", &m, &n);
	vector<int> rec;
	for(int kase = 1; kase <= m; ++kase) {
		int u, c; scanf("%d%d", &u, &c);
		rec.clear();
		deg[u].push_back(c);
//		degreeArchive[u].push_back(c);
//		printf("deg[%d][%d] = %d\n", u, (int)deg[u].size() - 1, c);
		val[u].push_back(0);
		while(c--) {
			int v; scanf("%d", &v);
			if(v == -1) v = 0;
			rec.push_back(v);
			T[v].push_back(pii(u, G[u].size()));
		}
		G[u].push_back(rec);
	}
	// toposortStoppable();
	f[0] = g[0] = 1;
	for(int u = 1; u <= n; ++u) f[u] = INF, g[u] = 0;
	Dijkstra();
	for(int u = 0; u <= n; ++u) canInf[u] = false, status[u] = NOT;
	for(int u = 0; u <= n; ++u) if(status[u] == NOT && g[u] == 0) DFS(u);
	for(int u = 1; u <= n; ++u) if(canInf[u]) g[u] = -2;
	/*for(int u = 1; u <= n; ++u) {
		f[u] = g[u] = 0;
		if(canInf[u]) g[u] = -2;
		if(unstoppable[u]) f[u] = g[u] = -1;
	}*/
}

void dp(int u) {
	if(g[u]) return;
	LL &ans = g[u];
	for(auto &l : G[u]) {
		LL cur = 0;
		for(int v : l) {
			dp(v);
			if(g[v] == -1) goto BYEBYE;
			cur += g[v];
		}
		chmax(ans, cur);
		BYEBYE : {}
	}
	chmin(ans, FINITE);
}

int main() {
	initialize();
//	copyDegree();
	for(int u = 1; u <= n; ++u) dp(u);
	for(int u = 1; u <= n; ++u) {
		printf("%lld %lld\n", f[u], g[u]);
	}
	return 0;
}