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
#include <iomanip>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;

// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 300228;


int n, k;
string s;
vector<int> who[MAXN];
int sz[MAXN];
int cnt[MAXN][2];
int det[MAXN];
int parent[MAXN];
int col[MAXN];
vector<int> g[MAXN];


int findset(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = findset(parent[v]);
}


int ans = 0;

void makeone(int v) {
	int u = findset(v);
	if (det[u] != -1) {
		return;
	}
	ans -= min(cnt[u][0], cnt[u][1]);
	det[u] = col[v];
	ans += cnt[u][det[u]];
}


void makezero(int v) {
	int u = findset(v);
	if (det[u] != -1) {
		return;
	}
	ans -= min(cnt[u][0], cnt[u][1]);
	det[u] = 1 - col[v];
	ans += cnt[u][det[u]];
}


void del(int i) {
	if (det[i] != -1) {
		ans -= cnt[i][det[i]];
	} else {
		ans -= min(cnt[i][0], cnt[i][1]);
	}
}


void add(int i) {
	if (det[i] != -1) {
		ans += cnt[i][det[i]];
	} else {
		ans += min(cnt[i][0], cnt[i][1]);
	}
}


void unitediff(int a, int b) {
	int ta = col[a];
	int tb = col[b];
	a = findset(a);
	b = findset(b);
	if (a == b) {
		return;
	}
	if (sz(g[a]) < sz(g[b])) {
		swap(a, b);
		swap(ta, tb);
	}
	bool need = false;
	if (ta == tb) {
		need = true;
	}
	for (auto x: g[b]) {
		if (need) {
			col[x] ^= 1;
		}
		g[a].pb(x);
	}
	g[b].clear();
	if (need) {
		if (det[b] != -1) {
			det[b] ^= 1;
		}
		swap(cnt[b][0], cnt[b][1]);
	}
	del(b);
	del(a);
	cnt[a][0] += cnt[b][0];
	cnt[a][1] += cnt[b][1];
	parent[b] = a;
	if (det[b] != -1) {
		det[a] = det[b];
	}
	add(a);
}


void unitesame(int a, int b) {
	int ta = col[a];
	int tb = col[b];
	a = findset(a);
	b = findset(b);
	if (a == b) {
		return;
	}
	if (sz(g[a]) < sz(g[b])) {
		swap(a, b);
		swap(ta, tb);
	}
	bool need = false;
	if (ta != tb) {
		need = true;
	}
	for (auto x: g[b]) {
		if (need) {
			col[x] ^= 1;
		}
		g[a].pb(x);
	}
	g[b].clear();
	if (need) {
		if (det[b] != -1) {
			det[b] ^= 1;
		}
		swap(cnt[b][0], cnt[b][1]);
	}
	del(b);
	del(a);
	cnt[a][0] += cnt[b][0];
	cnt[a][1] += cnt[b][1];
	parent[b] = a;
	if (det[b] != -1) {
		det[a] = det[b];
	}
	add(a);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < k; i++) {
		parent[i] = i;
		det[i] = -1;
		cnt[i][0] = 0;
		cnt[i][1] = 1;
		col[i] = 1;
		g[i].pb(i);
		int c;
		cin >> c;
		for (int j = 0; j < c; j++) {
			int id;
			cin >> id;
			who[id - 1].pb(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (!who[i].empty()) {
				if (sz(who[i]) == 1) {
					makezero(who[i][0]);
				} else {
					unitesame(who[i][0], who[i][1]);
				}
			}
		} else {
			if (!who[i].empty()) {
				if (sz(who[i]) == 1) {
					makeone(who[i][0]);
				} else {
					//cout << who[i][0] << ' ' << who[i][1] << endl;
					unitediff(who[i][0], who[i][1]);
				//	cout << cnt[findset(who[i][1])][0] << ' ' << cnt[findset(who[i][1])][1] << endl;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}