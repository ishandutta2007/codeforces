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
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



const int MAXN = 300228;


int n, m;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> res;
bool in[MAXN];


void dfs(int start) {
	used[start] = true;
	bool was = false;
	for (auto f: g[start]) {
		if (in[f]) {
			was = true;
		}
	}
	if (!was) {
		in[start] = true;
		res.pb(start);
	}
	for (auto f: g[start]) {
		if (!used[f]) {
			dfs(f);
		}
	}
}


void dfs1(int u) {
	used[u] = true;
	for (auto h: g[u]) {
		if (in[h] || in[u]) {
			if (!used[h]) {
				dfs1(h);
			}
		}
	}
}


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		used[i] = false;
		in[i] = false;
	}
	for (int it = 0; it < m; it++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}	
	res.clear();
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			dfs(i);
			cnt++;
		}
	}
	if (cnt > 1) {
		cout << "NO\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		used[i] = false;
	}
	dfs1(1);
	for (int i = 1; i <= n; i++) {
		assert(used[i]);
	}
	cout << "YES\n";
	cout << sz(res) << '\n';
	sort(all(res));
	for (auto x: res) {
		cout << x << ' ';
	}
	cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}    
   	return 0;
}