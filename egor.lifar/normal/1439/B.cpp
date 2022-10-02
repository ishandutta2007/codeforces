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


int n, m, k;
vector<int> g[MAXN];
int deg[MAXN];
bool del[MAXN];
bool in[MAXN];
map<int, bool> kek[MAXN];
int degs[MAXN];


bool check(vector<int> x) {
	for (auto y: x) {
		if (sz(g[y]) < sz(x) - 1) {
			return false;
		}
	}
	vector<int> d;
	for (int i = 0; i < sz(x); i++) {
		d.pb(degs[x[i]]);
	}
	sort(all(d));
	for (int i = 0; i < sz(x); i++) {
		if (d[i] < i) {
			return false;
		}
	}
	for (int i = 0; i < sz(x); i++) {
		for (int j = i + 1; j < sz(x); j++) {
			if (kek[x[i]].find(x[j]) == kek[x[i]].end()) {
				return false;
			}
		}
	}
	return true;
}


void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		g[i].clear();
		kek[i].clear();
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		kek[a][b] = true;
		kek[b][a] = true;
		g[a].pb(b);
		g[b].pb(a);
	}
	set<pair<int, int> > s;
	for (int i = 0; i < n; i++) {
		deg[i] = sz(g[i]);
		del[i] = false;
		s.insert(mp(deg[i], i));
		in[i] = false;
	}
	vector<int> order;
	while (!s.empty()) {
		auto x = *s.begin();
		if (x.first >= k) {
			break;
		}
		s.erase(x);
		order.pb(x.second);
		del[x.second] = true;
		for (auto y: g[x.second]) {
			if (!del[y]) {
				s.erase(mp(deg[y], y));
				deg[y]--;
				s.insert(mp(deg[y], y));
			}
		}
	}
	if (!s.empty()) {
		cout << 1 << ' ' << sz(s) << '\n';
		for (auto h: s) {
			cout << h.second + 1 << ' ';
		}
		cout << '\n';
		return;
	}
	reverse(all(order));
	for (int i = 0; i < sz(order); i++) {
		degs[order[i]] = 0;
		vector<int> kek;
		for (auto h: g[order[i]]) {
			if (in[h]) {
				degs[order[i]]++;
				kek.pb(h);
			}
		}
		kek.pb(order[i]);
		if (sz(kek) == k) {
			if (check(kek)) {
				cout << 2 << '\n';
				for (auto y: kek) {
					cout << y + 1 << ' ';
				}
				cout << '\n';
				return;
			}
		}
		in[order[i]] = true;
	}
	cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}