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
#include <random>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 100228;


int n, m;
vector<pair<int, int> > g[MAXN];
ll dist[MAXN];
int x[MAXN], y[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	int sx, sy, fx, fy;
	cin >> sx >> sy >> fx >> fy;
	g[0].pb(mp(m + 1, abs(sx - fx) + abs(sy - fy)));
	vector<pair<int, int> > st, st1;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		st.pb(mp(x[i], i));
		st1.pb(mp(y[i], i));
		g[0].pb(mp(i, min(abs(x[i] - sx), abs(y[i] - sy))));
		g[i].pb(mp(m + 1, abs(x[i] - fx) + abs(y[i] - fy)));
	}	
	sort(all(st));
	sort(all(st1));
	for (int i = 0; i < m - 1; i++) {
		int id = st[i].second;
		int id1 = st[i + 1].second;
		int val = abs(st[i].first - st[i + 1].first);
		g[id].pb(mp(id1, val));
		g[id1].pb(mp(id, val));
	}
	for (int i = 0; i < m - 1; i++) {
		int id = st1[i].second;
		int id1 = st1[i + 1].second;
		int val = abs(st1[i].first - st1[i + 1].first);
		g[id].pb(mp(id1, val));
		g[id1].pb(mp(id, val));
	}
	for (int i = 0; i <= m + 1; i++) {
		dist[i] = 1e18;
	}
	dist[0] = 0;
	set<pair<ll, int> > s;
	s.insert(mp(0, 0));
	while (!s.empty()) {
		auto xx = *s.begin();
		s.erase(xx);
		int u = xx.second;
		for (auto h: g[u]) {
			if (dist[h.first] > dist[u] + h.second) {
				s.erase(mp(dist[h.first], h.first));
				dist[h.first] = dist[u] + h.second;
				s.insert(mp(dist[h.first], h.first));
			}
		}
	}
	cout << dist[m + 1] << '\n';
}