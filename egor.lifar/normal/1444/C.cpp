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
const int MAXN = 500228;


int n, m, k;
int c[MAXN];
vector<int> who[MAXN];
vector<int> v[MAXN];
bool bad[MAXN];
int used[MAXN];
bool was = false;
vector<int> st[2];
int parent[MAXN];
int bade[MAXN];
map<pair<int, int>, vector<pair<int, int> > > whos;


int findset(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = findset(parent[v]);
}


void dfs(int u) {
	st[used[u] - 1].pb(u);
	for (auto h: v[u]) {
		if (!used[h]) {
			used[h] = 3 - used[u];
			dfs(h);
		} else if (used[h] == used[u]) {
			was = true;
		}
	}
}

int ukr = 0;
int usede[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		who[c[i]].pb(i);
		parent[i] = i;
		bade[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (c[a] == c[b]) {
			v[a].pb(b);
			v[b].pb(a);
		}
		if (c[a] > c[b]) {
			swap(a, b);
		}
		if (c[a] != c[b]) {
			whos[mp(c[a], c[b])].pb(mp(a, b));
		}
	}
	for (int i = 1; i <= k; i++) {
		if (who[i].empty()) {
			continue;
		}
		for (auto j: who[i]) {
			if (!used[j]) {
				used[j] = 1;
				was = false;
				st[0].clear();
				st[1].clear();
				dfs(j);
				if (was) {
					bad[i] = true;
					break;
				}
				for (auto x: st[0]) {
					parent[findset(x)] = findset(st[0][0]);
				}
				for (auto x: st[1]) {
					parent[findset(x)] = findset(st[1][0]);
				}
				if (!st[0].empty() && !st[1].empty()) {
					bade[findset(st[0][0])] = findset(st[1][0]);
					bade[findset(st[1][0])] = findset(st[0][0]);
				}
			}
		}
	}
	ll cnt = 0;
	for (int i = 1; i <= k; i++) {
		if (!bad[i]) {
			cnt++;
		}
	}
	ll val = cnt * (cnt - 1) / 2;
	ll ans = 0;
	for (auto x: whos) {
		if (bad[x.first.first] || bad[x.first.second]) {
			continue;
		}
		val--;
		vector<int> str;
		for (auto y: x.second) {
			str.pb(findset(y.first));
			str.pb(findset(y.second));
		}
		sort(all(str));
		str.resize(distance(str.begin(), unique(all(str))));
		auto z = str;
		for (auto x: str) {
			if (bade[x] != -1) {
				z.pb(bade[x]);
			}
		}
		str = z;
		sort(all(str));
		str.resize(distance(str.begin(), unique(all(str))));
		for (auto x: str) {
			used[x] = 0;
			v[x].clear();
		}
		bool bad = false;
		for (auto y: x.second) {	
			y.first = findset(y.first);
			y.second = findset(y.second);
			if (y.first == y.second) {
				bad = true;
				break;
			}
			v[y.first].pb(y.second);
			v[y.second].pb(y.first);
		}
		for (auto x: str) {
			if (bade[x] != -1) {
				v[x].pb(bade[x]);
			}
		}
		if (bad) {
			continue;
		}
		was = false;
		for (auto x: str) {
			if (!used[x]) {
				st[0].clear();
				st[1].clear();
				used[x] = 1;
				dfs(x);
				if (was) {
					bad = true;
					break;
				}
			}
		}
		if (!bad) {
			ans++;
		}
	}
	ans += val;
	cout << ans << '\n';
}