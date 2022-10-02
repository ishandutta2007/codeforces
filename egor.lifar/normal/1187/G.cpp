/*
 












 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
    
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 8200;
const long long INF = 1e14;


struct edge {
	int u, v;
	long long cap, flow;
	long long cost;
	long long rem() {
		return cap - flow;
	}
	edge(){}
	edge(int _u, int _v, long long _cap, long long _flow, long long _cost) {
		u = _u;
		v = _v;
		cap = _cap;
		flow = _flow;
		cost = _cost;
	}
};


int nodes; 
vector<int> g[MAXN];
vector<edge> e;


void add_edge(int u, int v, long long cap, long long cost) {
	g[u].pb(sz(e));
	e.pb(edge(u, v, cap, 0, cost));
	g[v].pb(sz(e));
	e.pb(edge(v, u, 0, 0, -cost));
}


long long dist[MAXN], mncost;
int pre[MAXN];
long long cap[MAXN], mxflow;
bool inq[MAXN];


void flow(int s, int t) {
	memset(inq, 0, sizeof(inq));
	mxflow = mncost = 0;
	while (true) {
		fill(dist, dist + nodes, INF);
		dist[s] = 0;
		memset(pre, -1, sizeof(pre));
		pre[s] = 0;
		memset(cap, 0, sizeof(cap));
		cap[s] = INF;
		queue<int> q;
		q.push(s);
		inq[s]=1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			inq[u] = 0;
			for (int it = 0; it < sz(g[u]); it++) {
				int i = g[u][it];
				edge &f = e[i];
				if (f.rem() && dist[f.v] > dist[u] + f.cost + 1e-9) {
					dist[f.v] = dist[u] + f.cost;
					pre[f.v] = i;
					cap[f.v] = min(cap[u], f.rem());
					if (!inq[f.v]) {
						q.push(f.v);
						inq[f.v] = 1;
					}
				}
			}
		}
		if (pre[t] < 0) {
			break;
		}
		mxflow +=cap[t];
		mncost += cap[t] * dist[t];
		int v = t;
		while (v != s) {
			e[pre[v]].flow += cap[t];
			e[pre[v] ^ 1].flow -= cap[t];
			v = e[pre[v]].u;
		}
	}
}
 

int n, m, k, c, d;
 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m >> k >> c >> d;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		x--;
		add_edge(0, x + 1, 1, 0);
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		for (int i = 0; i < 105; i++) {
			for (int j = 0; j < 51; j++) {
				add_edge(i * n + x + 1, (i + 1) * n + y + 1, 1, c + d * (2 * j + 1));
				add_edge(i * n + y + 1, (i + 1) * n + x + 1, 1, c + d * (2 * j + 1));
			}
		}
	}
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < n; j++) {
			add_edge(i * n + j + 1, (i + 1) * n + j + 1, 51, c);
		}
	}
	for (int i = 0; i < 105; i++) {
		add_edge(i * n + 1, 105 * n + 1, 51, 0);
	}
	nodes = 6 + 107 * n;
	flow(0, 105 * n + 1);
	cout << mncost << '\n';
	return 0;
}