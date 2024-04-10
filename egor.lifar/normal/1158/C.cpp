/*

Code for problem C by cookiedoth
Generated 12 May 2019 at 06.44 P



10%

30%

50%

70%

100%

o_O
-_-
z_z

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int _n, n;
vector<vector<int> > g;

void build(int v, int tl, int tr) {
	//cerr << "build " << v << " " << tl << " " << tr << endl;
	if (tl == tr) {
		return;
	}
	g[v].push_back(2 * v);
	g[v].push_back(2 * v + 1);
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
}

void make_edge(int u, int l, int r, int v, int tl, int tr) {
	//cerr << "make_edge " << u << " " << l << " " << r << " " << v << " " << tl << " " << tr << endl;
	if (l > r) {
		//cerr << "ret" << endl;
		return;
	}
	if (l == tl && r == tr) {
		g[u].push_back(v);
	}
	else {
		int tm = (tl + tr) >> 1;
		make_edge(u, l, min(r, tm), v * 2, tl, tm);
		make_edge(u, max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
	}
}

vector<int> out, _out, used;

void dfs(int v) {
	used[v] = 1;
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			dfs(v1);
		}
	}
	_out[v] = out.size();
	out.push_back(v);
}

void solve_one() {
	//cerr << "solve" << endl;
	cin >> _n;
	n = 1;
	while (n < _n) {
		n <<= 1;
	}
	//cerr << "n = " << n << endl;
	int V = 2 * n;
	g.resize(V);
	for (int i = 0; i < V; ++i) {
		g[i].clear();
	}
	build(1, 0, n - 1);
	//cerr << "kek" << endl;
	vector<int> nxt(_n);
	//cerr << "_n = " << _n << endl;
	for (int i = 0; i < _n; ++i) {
		//cerr << "i = " << i << endl;
		cin >> nxt[i];
		if (nxt[i] == -1) {
			continue;
		}
		nxt[i]--;
		make_edge(i + n, i + 1, nxt[i] - 1, 1, 0, n - 1);
		if (nxt[i] < _n) {
			g[nxt[i] + n].push_back(i + n);
		}
		//cerr << "kek" << endl;
	}
	//cerr << "lol" << endl;
	out.clear();
	_out.assign(V, 0);
	used.assign(V, 0);
	for (int i = 0; i < V; ++i) {
		if (used[i] == 0) {
			dfs(i);
		}
	}
	/*output(all(out));
	output(all(_out));
	cerr << "g" << endl;
	for (int i = 0; i < V; ++i) {
		cerr << "i = " << i << ", ";
		output(all(g[i]));
	}*/
	for (int i = 0; i < V; ++i) {
		for (auto v : g[i]) {
			if (_out[v] > _out[i]) {
				//cerr << i << " -> " << v << endl;
				cout << -1 << endl;
				return;
			}
		}
	}
	vector<int> ans(n);
	int ptr = 0;
	for (auto x : out) {
		if (x >= n) {
			ans[x - n] = ptr++;
		}
	}
	for (int i = 0; i < _n; ++i) {
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		solve_one();
	}
}