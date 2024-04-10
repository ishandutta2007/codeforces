//MIPT Cryptozoology
//Room 202
#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define itn int

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void precalc();

int TESTNUM = 0;
#define FILENAME ""

int main() {
	string s = FILENAME;
#ifdef YA
	//assert(!s.empty());
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cerr<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
	cin.tie(0);
#endif
	//cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	precalc();
	int t = 1;
	//cin >> t;
	while (t--) {
		++TESTNUM;
		solve();
	}
#ifdef YA
	cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
	return 0;
}

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

//#define int li


void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> col(n, -1);
	for (int i = 0; i < n; ++i) {
		int has[2] = { 0, 0 };
		for (int to : g[i]) {
			if (col[to] != -1) {
				++has[col[to]];
			}
		}
		if (has[0] < has[1]) {
			col[i] = 0;
		}
		else {
			col[i] = 1;
		}
	}
	vector<vector<int>> lists(n);
	int T = 0;
	for (int i = 0; i < n; ++i) {
		int sz;
		cin >> sz;
		lists[i].resize(sz);
		for (int j = 0; j < sz; ++j) {
			cin >> lists[i][j];
			T = max(T, lists[i][j]);
			--lists[i][j];
		}
	}
	
	vector<int> color(T);
	while (true) {
		for (int i = 0; i < T; ++i) {
			color[i] = rand() & 1;
		}
		bool f = true;
		for (int i = 0; i < n; ++i) {
			bool has[2] = { false, false };
			for (int v : lists[i]) {
				has[color[v]] = true;
			}
			if (!has[0] || !has[1]) {
				f = false;
				break;
			}
		}
		if (f) {
			break;
		}
	}

	for (int i = 0; i < n; ++i) {
		bool f = false;
		for (int v : lists[i]) {
			if (color[v] == col[i]) {
				f = true;
				cout << v + 1 << ' ';
				break;
			}
		}
		assert(f);
	}
	cout << "\n";

	int good = 0;
	for (int i = 0; i < n; ++i) {
		for (int to : g[i]) {
			if (col[to] != col[i]) {
				++good;
			}
		}
	}
	assert(good >= m);

	for (int i = 0; i < T; ++i) {
		cout << color[i] + 1 << ' ';
	}
	cout << "\n";

}