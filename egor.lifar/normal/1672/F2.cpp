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


const int MAXN = 200228;


int n;
int a[MAXN];
int b[MAXN];
vector<int> g[MAXN];
int used[MAXN];
int uk;


void dfs(int u) {
	used[u] = true;
	for (auto h: g[u]) {
		if (!used[h]) {
			dfs(h);
		}
	}
	used[u] = ++uk;
}




void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
	}
	for (int i = 0; i < n; i++) {
		g[i].clear();
		used[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		g[a[i]].pb(b[i]);
	}
	int majorant = 0;
	for (int i = 0; i < n; i++) {
		if (sz(g[i]) > sz(g[majorant])) {
			majorant = i;
		}
	}
	used[majorant] = true;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}
	used[majorant] = 0;
	for (int x = 0; x < n; x++) {
		if (x == majorant) {
			continue;
		}
		for (auto h: g[x]) {
			if (used[h] >= used[x]) {
				cout << "WA\n";
				return;
			}
		}
	}
	cout << "AC\n";
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