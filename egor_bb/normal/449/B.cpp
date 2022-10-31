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
	int to, cost, type;
	Edge(){};
	Edge(int a, int b, int c){to = a; cost = b; type = c;};
};

ll n, m, k, num[100005];
vector < vector <Edge> > g;
set <pll> s;
vector <ll> d, par;
vector <pll> mass;

ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}

int check(int v){
	for (int i = 0; i < g[v].size(); i++){
		if (!g[v][i].type && d[g[v][i].to] + g[v][i].cost == d[v]) return -1;
	}
	return 1;
}


int main(){
//	ifstream cin ("in.txt");
	cin >> n >> m >> k;
	g.resize(n);
	par.resize(n, -1);
	d.resize(n, INFll);
	for (int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g[a].pb(Edge(b, w, 0));
		g[b].pb(Edge(a, w, 0));
	}
	for (int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		a--;
		g[0].pb(Edge(a, b, 1));
		g[a].pb(Edge(0, b, 1));
	}
	d[0] = 0;
	s.insert(mp(0, 0));
	while (!s.empty()){
		int v = s.begin()->second;
		s.erase(s.begin());
		for (int i = 0; i < g[v].size(); i++){
			ll to = g[v][i].to, cost = g[v][i].cost;
			if (cost + d[v] < d[to]){
				s.erase(mp(d[to], to));
				d[to] = d[v] + cost;
				s.insert(mp(d[to], to));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < g[0].size(); i++){
		if (g[0][i].type == 1){
			if (!num[g[0][i].to]){
				num[g[0][i].to] = check(g[0][i].to);
				if (num[g[0][i].to] == -1) ans++;
			} else ans++;
		}
	}
	cout << ans;
	return 0;
}