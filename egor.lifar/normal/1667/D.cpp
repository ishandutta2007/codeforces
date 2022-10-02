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
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
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
const int MAXN = 200229;


int n;
vector<int> g[MAXN];
int jump[MAXN];
int id[MAXN];
bool bad = false;


void dfs(int u, int pr = -1) {
	int cnt[2] = {0, 0};
	for (auto h: g[u]) {
		if (h == pr) {
			continue;
		}
		jump[h] = u;
		dfs(h, u);
		cnt[id[h]]++;
	}
	if (pr != -1) {
		id[u] = cnt[0] >= cnt[1];
		cnt[id[u]]++;
	} 
	int diff = cnt[1] - cnt[0];
	if (diff < 0 || diff > 1) {
		bad = true;
	}
}



void restore(int u) {
	vector<int> z[2];
	for (auto h: g[u]) {
		if (jump[h] == u) {
			z[id[h]].pb(h);
		} else {
			z[id[u]].pb(u);
		}	
	}
	int len = sz(g[u]);
	int it = len & 1;
	for (int i = 0; i < len; i++) {
		int d = z[it].back();
		if (d == u) {
			cout << u + 1 << ' ' << jump[u] + 1 << '\n';
		} else {
			restore(d);
		}
		z[it].pop_back();
		it ^= 1;
	}
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		g[i].clear();
		id[i] = 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	bad = false;
	dfs(0);
	if (bad) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	restore(0);
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
	//	cerr << t << endl;
		solve();
	}
}