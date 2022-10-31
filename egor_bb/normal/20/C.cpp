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



ll n, m;
vector < vector <pll> > g;
set <pll> s;
vector <ll> d, par;

ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}



int main(){
//	ifstream cin ("in.txt");
	cin >> n >> m;
	g.resize(n);
	par.resize(n, -1);
	d.resize(n, INFll);
	for (int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g[a].pb(mp(b, w));
		g[b].pb(mp(a, w));
	}
	d[0] = 0;
	s.insert(mp(0, 0));
	while (!s.empty()){
		int v = s.begin()->second;
		s.erase(s.begin());
		for (int i = 0; i < g[v].size(); i++){
			ll to = g[v][i].first, cost = g[v][i].second;
			if (cost + d[v] < d[to]){
				s.erase(mp(d[to], to));
				d[to] = d[v] + cost;
				par[to] = v;
				s.insert(mp(d[to], to));
			}
		}
	}
	if (par[n - 1] == -1) cout << -1;
	else {
		vector <ll> path;
		for (int i = n - 1; i != 0; i = par[i]){
			path.pb(i);
		}
		path.pb(0);
		for (int i = path.size() - 1; i >= 0; i--){
			cout << path[i] + 1 << " ";
		}
	}
	return 0;
}