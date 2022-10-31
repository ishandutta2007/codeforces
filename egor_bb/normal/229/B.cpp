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

ll n, m;
vector < vector <Edge> > g;
set <pll> s;
vector <ll> d;
vector <vector <ll> > time;

ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}




int main(){
//	ifstream cin ("in.txt");
	cin >> n >> m;
	g.resize(n);
	time.resize(n);
	d.resize(n, INFll);
	for (int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g[a].pb(Edge(b, w));
		g[b].pb(Edge(a, w));
	}
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		time[i].resize(k);
		for (int j = 0; j < k; j++) cin >> time[i][j];
	}
	d[0] = 0;
	s.insert(mp(0, 0));
	while (!s.empty()){
		int v = s.begin()->second;
		s.erase(s.begin());
		ll effcost = d[v];
		if (time[v].size() != 0){
			int f = lower_bound(time[v].begin(), time[v].end(), d[v]) - time[v].begin(), sz = time[v].size();
			if (f < sz && time[v][f] == d[v]) {
				f++;
				while (f < time[v].size() && abs (time[v][f] - time[v][f - 1]) <= 1) f++;
				effcost = time[v][f - 1] + 1;
			}
		}
		for (int i = 0; i < g[v].size(); i++){
			ll to = g[v][i].to, cost = g[v][i].cost;
			if (cost + effcost < d[to]){
				s.erase(mp(d[to], to));
				d[to] = effcost + cost;
				s.insert(mp(d[to], to));
			}
		}
	}

	if (d[n - 1] < INFll) cout << d[n - 1];
	else cout << -1;
	return 0;
}