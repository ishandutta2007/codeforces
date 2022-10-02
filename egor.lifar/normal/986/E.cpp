/*
 












 
 */
#pragma GCC target("sse4,tune=native")
#pragma GCC optimize("O3","unroll-loops")
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
    
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 100228;
const int MAXM = 10000000;
const int Mod = 1000000007;


int mul(int a, int b) {
	return (1LL * a * b) % Mod;
}


int powm(int a, int b) {
	if (b == 0) {
		return 1;
	} else if (b & 1) {
		return mul(a, powm(a, b - 1));
	} else {
		int g = powm(a, b >> 1);
		return mul(g, g);
	}
} 

int n;
vector<int> g[MAXN];
int a[MAXN];
bool composite[MAXM + 228];
vector<pair<int, short> > divs[MAXM + 228];
vector<int> need[MAXM + 228];
int zu[MAXN], zv[MAXN], zx[MAXN];
int zl[MAXN];
int in[MAXN], out[MAXN];
int jump[MAXN][18];
int timer = 0;
bool was[MAXM + 228];
bool good[MAXM + 228];
vector<int> gs[MAXN];



void dfs(int u, int prs = -1) {
	timer++;
	in[u] = timer;
	for (auto h: g[u]) {
		if (h != prs) {
			jump[h][0] = u;
			dfs(h, u);
		}
	}
	out[u] = timer;
}


bool is_ancestor(int a, int b) {
	return in[a] <= in[b] && out[b] <= out[a];
}


int lca(int a, int b) {
	if (is_ancestor(a, b)) {
		return a;
	}
	if (is_ancestor(b, a)) {
		return b;
	}
	for (int k = 17; k >= 0; k--) {
		if (!is_ancestor(jump[a][k], b)) {
			a = jump[a][k];
		}
	}
	return jump[a][0];
}


bool comp(int a, int b) {
	return in[a] < in[b];
}


unordered_map<int, int> deep[MAXN];


void dfs1(int u, int who) {
	deep[u][who] += (a[u] % who) == 0;
	for (auto h: gs[u]) {
		deep[h][who] = deep[u][who];
		dfs1(h, who);
	}
}


bool heh[MAXM + 228];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		heh[a[i]] = true;
	}
	int q;
	cin >> q;
	for (int it = 0; it < q; it++) {
		cin >> zu[it] >> zv[it] >> zx[it];
		heh[zx[it]] = true;
	}
	for (int i = 2; i <= MAXM; i++) {
		if (!composite[i]) {
			for (int j = i; j <= MAXM; j += i) {
				composite[j] = true;
				if (heh[j]) {
				int tj = j;
				int cnt = 0;
				while (tj % i == 0) {
					tj /= i;
					cnt++;
				}
				divs[j].pb({i, cnt});
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (auto x: divs[a[i]]) {
			int cur = 1;
			for (int t = 1; t <= x.second; t++) {
				cur *= x.first;
				need[cur].pb(i);
				was[cur] = true;
			}
		}
	}
	dfs(0);
	for (int k = 1; k <= 17; k++) {
		for (int i = 0; i < n; i++) {
			jump[i][k] = jump[jump[i][k - 1]][k - 1];
		}
	}
	for (int it = 0; it < q; it++) {
		zu[it]--;
		zv[it]--;
		zl[it] = lca(zu[it], zv[it]);
		for (auto x: divs[zx[it]]) {
			int cur = 1;
			for (int f = 1; f <= x.second; f++) {
				cur *= x.first;
				need[cur].pb(zu[it]);
				need[cur].pb(zv[it]);
				need[cur].pb(zl[it]);
				good[cur] = true;
			}
		}
	}
	for (int who = 1; who <= MAXM; who++) {
		if (was[who] && good[who]) {
			sort(all(need[who]), comp);
			need[who].resize(distance(need[who].begin(), unique(all(need[who]))));
			vector<int> st;
			for (auto x: need[who]) {
				if (st.empty()) {
					st.pb(x);
					continue;
				}
				if (is_ancestor(st.back(), x)) {
					gs[st.back()].pb(x);
					st.pb(x);
					continue;
				}
				while (sz(st) >= 2 && !is_ancestor(st.back(), x)) {
					st.pop_back();
				}
				if (is_ancestor(st.back(), x)) {
					gs[st.back()].pb(x);
					st.pb(x);
					continue;
				}
				int f = lca(st.back(), x);
				gs[f].pb(st.back());
				st.pop_back();
				st.pb(f);
				gs[f].pb(x);
				st.pb(x);
			}
			dfs1(st[0], who);
			for (auto x: need[who]) {
				gs[x].clear();
			}
		}
	}
	//cout << lca(1, 2) << endl;
	//cout << deep[1][2] << ' ' << deep[2][2] << endl;
	for (int it = 0; it < q; it++) {
		int res = 1;
		for (auto x: divs[zx[it]]) {
			int cur = 1;
			int ans = 0;
			for (int f = 1; f <= x.second; f++) {
				cur *= x.first;
				if (!was[cur]) {
					break;
				}
				ans += deep[zu[it]][cur] + deep[zv[it]][cur] - deep[zl[it]][cur] * 2 + (a[zl[it]] % cur == 0 ? 1: 0);
			}
			//cout << x.first << ' ' << ans << endl;
			res = mul(res, powm(x.first, ans));
		}
		cout << res << '\n';
	}
	return 0;
}