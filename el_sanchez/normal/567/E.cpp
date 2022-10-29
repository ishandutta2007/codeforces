//#define _GLIBCXX_DEBUG
//#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <cassert>
#include <ctime>
               
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 211111;
const ll LINF = 1E18;

int n, m, a, b, c, s, t;
int ansType[MAXN], ans[MAXN];
ll dist[2][MAXN], len;
vector<pair<pii, int>> g[2][MAXN];
vector<pii> g2[MAXN];
vector<pii> edges[MAXN];
set<pair<ll, int>> q;
       
void dijkstra(int v, int id) {
	forn(i, n)
		dist[id][i] = LINF;
	dist[id][v] = 0;
	
	q.clear();
	forn(i, n)
		q.insert({dist[id][i], i});
		
	while (!q.empty()) {
		auto cur = *q.begin();
		q.erase(cur);

		v = cur.Y;
		for (auto e: g[id][v]) {
			int w = e.X.X;
			int weight = e.X.Y;
			if (dist[id][w] > dist[id][v] + weight) {
				q.erase({dist[id][w], w});
				dist[id][w] = dist[id][v] + weight;
				q.insert({dist[id][w], w}); 					
			}
		}					
	}
}

int pos[MAXN], used[MAXN], usedEdges[MAXN], sz;
vector<pii> way;
int start, open[MAXN], close[MAXN];
bool found;

void dfs(int v) {
	used[v] = 1;
	if (v == t) {
		found = 1;
		return;	
	}
	
	for (auto e: g2[v])
		if (!used[e.X]) {
			way.pb({v, e.Y});
			dfs(e.X);
			if (found)
				return;
			way.pop_back();
		}	
}

void dfs2(int v) {
	used[v] = 1;
	
	for (auto e: g2[v]) {
		if (usedEdges[e.Y])
			continue;
		
		int w = e.X;
		if (!used[w]) 
			dfs2(w);
		if (pos[w] != -1) {
			open[start]++;
			close[pos[w]]++;		
		}
	}	
}

int main() {
	
	scanf("%d%d%d%d", &n, &m, &s, &t);
	s--;
	t--;
	forn(i, m) {
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		g[0][a].pb({{b, c}, i});
		g[1][b].pb({{a, c}, i});
	}
	 
	dijkstra(s, 0);
	dijkstra(t, 1);
	
	//forn(i, n)
	//	cout << dist[0][i] << ' ' << dist[1][i] << '\n';

	len = dist[0][t];
	assert(len == dist[1][s]);
	
	forn(v, n)
		for (auto e: g[0][v]) {
			int w = e.X.X;
			int weight = e.X.Y;
			if (dist[0][v] + weight + dist[1][w] == len)
				g2[v].pb({w, e.Y});			
		}

	found = 0;
	dfs(s);
	
	memset(pos, -1, sizeof(pos));
	
	sz = way.size();
	forn(i, sz) {
		usedEdges[way[i].Y] = 1;
		pos[way[i].X] = i;
	}
	pos[t] = sz;
	
	assert(pos[s] != -1);
	assert(pos[t] != -1);
	
	memset(used, 0, sizeof(used));
	
	forn(i, sz)
		if (!used[way[i].X]) {
			start = i;
			dfs2(way[i].X);
		}
	
	int curOpen = 0;
	forn(i, sz) {
		curOpen += open[i];
		if (curOpen == 0)
			ansType[way[i].Y] = 1;
		curOpen -= close[i + 1];
		assert(curOpen >= 0);	
	}
	
	forn(v, n)
		for (auto e: g[0][v]) {
			int w = e.X.X;
			int weight = e.X.Y;
			if (ansType[e.Y] == 1)
				continue;
			if (len - dist[0][v] - dist[1][w] - 1 > 0) {
				ansType[e.Y] = 2;
				ans[e.Y] = weight - (len - dist[0][v] - dist[1][w] - 1);
			}
		}
	
	forn(i, m)
		if (ansType[i] == 0)
			cout << "NO\n";
		else if (ansType[i] == 1)
			cout << "YES\n";
		else {
			cout << "CAN ";
			printf("%d\n", ans[i]);
		}
		
	return 0;
}