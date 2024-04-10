//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
/*
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
*/			   
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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9; 
const int MAXN = 100500;

int n, m, a, b, c;
vector<pii> g[MAXN];

int final[MAXN];
int nxtFinal[MAXN], lenTo[MAXN];

int dist[MAXN];
vi curLevel[MAXN];
int good[MAXN], nxt[MAXN];
queue<int> q;
string ans;
vi path;

void bfs0(int v) {
	forn(i, n)
		lenTo[i] = INF;

	lenTo[v] = 0;
	nxtFinal[v] = -1;
	final[v] = 1;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		
		for (auto p: g[v]) {
			if (p.Y == 0) {
				int w = p.X;
				if (!final[w]) {
					final[w] = 1;
					nxtFinal[w] = v;
					lenTo[w] = lenTo[v] + 1;
					q.push(w);	
				}			
			}
		}
	}
}

void bfs(int s) {
	forn(i, n)
		dist[i] = INF;
	
	while (!q.empty())
		q.pop();
		
	dist[s] = 0;
	q.push(s);
	while (!q.empty()) {
		s = q.front();
		q.pop();

		for (auto p: g[s]) {
			int v = p.X;
			if (dist[v] == INF) {
				dist[v] = dist[s] + 1;
				q.push(v);
			}
		}
	}
}

int main() {

	cin >> n >> m;
	forn(i, m) {
		scanf("%d%d%d", &a, &b, &c);
		g[a].pb({b, c});
		g[b].pb({a, c});
	}

	bfs0(n - 1);
	bfs(0);
	
	int bestDist = INF;
	forn(i, n)
		if (final[i])
			bestDist = min(bestDist, dist[i]);
			
	forn(i, n)
		if (dist[i] != INF)
			curLevel[dist[i]].pb(i);
	
	memset(nxt, -1, sizeof(nxt));
	for (int i = bestDist; i >= 0; i--) {
		int minCost = INF;
		
		for (auto v: curLevel[i]) {
			if (final[v] && i == bestDist) {
				good[v] = 1;
				nxt[v] = -1;
			}
			if (!good[v])
				continue;
			
			for (auto p: g[v]) {
				int w = p.X;
				if (dist[w] + 1 == dist[v]) {
					minCost = min(minCost, p.Y);
				}
			}
		}

		//assert(minCost < INF);
		
		for (auto v: curLevel[i]) {
			if (!good[v])
				continue;
			for (auto p: g[v]) {
				int w = p.X;
				if (dist[w] + 1 == dist[v] && p.Y == minCost) {
					good[w] = 1;
					if (nxt[w] == -1 || lenTo[nxt[w]] > lenTo[v]) {
						nxt[w] = v;
					}
				}
			}
		}
	}
	
	assert(good[0]);
	/*
	forn(i, n)
		cout << good[i];
	cout << '\n';
	*/
	int v = 0;
	ans = "";
	
	bool t = 0;
	while (v != n - 1) {
		path.pb(v);
		if (final[v])
			t = 1;
		for (auto p: g[v]) {
			int w = p.X;
			if (!t) {
				if (w == nxt[v]) {
					ans += char('0' + p.Y);
					v = w;
					break;
				}
			} else {
				if (w == nxtFinal[v]) {
					ans += '0';
					v = w;
					break;
				}				
			}
		}
	}
	
	while (ans.back() == '0' && ans.size() > 1)
		ans.pop_back();
		
	path.pb(n - 1);
	reverse(all(ans));
	cout << ans << '\n';
	cout << path.size() << '\n';
	forn(i, path.size())
		printf("%d ", path[i]);
	
	return 0;
}