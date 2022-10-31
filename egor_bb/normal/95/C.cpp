#pragma comment (linker, "/STACK:100000000000")

#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e17 + 7)
#define sort stable_sort

using namespace std;

struct Edge{
	int to, cost;
	Edge(){};
	Edge(int a, int b){to = a; cost = b;};
};

ll n, m, x, y;
vector < vector <Edge> > g[2];
set <pll> s;
vector <ll> ans;
vector <vector <ll> > d;

ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}




int main(){
//	ifstream cin ("in.txt");
	cin >> n >> m;
	cin >> x >> y;
	x--; y--;
	g[0].resize(n);
	g[1].resize(n);
	ans.resize(n, INFll);
	d.resize(n, vector <ll>(n, INFll));
	for (int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g[0][a].pb(Edge(b, w));
		g[0][b].pb(Edge(a, w));
	}
	for (int k = 0; k < n; k++){
		d[k][k] = 0;
		s.insert(mp(0, k));
		while (!s.empty()){
			int v = s.begin()->second;
			s.erase(s.begin());
			for (int i = 0; i < g[0][v].size(); i++){
				ll to = g[0][v][i].to, cost = g[0][v][i].cost;
				if (cost + d[k][v] < d[k][to]){
					s.erase(mp(d[k][to], to));
					d[k][to] = d[k][v] + cost;
					s.insert(mp(d[k][to], to));
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < n; j++){
			if (d[i][j] <= a){
				g[1][i].pb(Edge(j, b));
			}
		}
	}

	ans[x] = 0;
	s.insert(mp(0, x));
	while (!s.empty()){
		int v = s.begin()->second;
		s.erase(s.begin());
		for (int i = 0; i < g[1][v].size(); i++){
			ll to = g[1][v][i].to, cost = g[1][v][i].cost;
			if (cost + ans[v] < ans[to]){
				s.erase(mp(ans[to], to));
				ans[to] = ans[v] + cost;
				s.insert(mp(ans[to], to));
			}
		}
	}

	if (ans[y] < INFll) cout << ans[y];
	else cout << -1;
	return 0;
}