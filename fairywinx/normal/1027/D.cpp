// #define GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
// #include <cmath>
#include <bitset>

#include <algorithm>
// #define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif
	srand(time(0));
}

const int N = 2e5 + 228;

vector<int> G[N];
int mx_up[N];
int used[N];
int d[N];

void dfs(int v, int h, vector<int> &comp, int c) {
	used[v] = c;
	d[v] = h;
	mx_up[v] = 2e5 + 228;
	for(auto i: G[v]) {
		if (used[i] && used[i] != c) 
			continue;
		if (!used[i]) {
			dfs(i, h + 1, comp, c);
			mx_up[v] = min(mx_up[v], mx_up[i]);
		}
		mx_up[v] = min(mx_up[v], d[i]);
	}
	// cout << v + 1 << ' ' << h << ' ' << mx_up[v] << '\n';
	if (mx_up[v] <= h)
		comp.push_back(v);
}

signed main() {
	setup();
	
	int n;
	cin >> n;
	vector<int> c(n);
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		G[i].push_back(a - 1);
	}
	vector<vector<int>> ans;
	int res = 0;
	for(int i = 0; i < n; ++i) {
		if (!used[i]) {
			ans.push_back(vector<int> ());
			dfs(i, 0, ans.back(), ans.size());
		}
	}
	for(auto i: ans) {
		// cout << "MEOW:";
		int mn = 1e9;
		for(auto j: i) {
			// cout << j << ' ';
			mn = min(mn, c[j]);
		}
		// cout << '\n';
		if (i.size() > 0)
			res += mn;
	}
	cout << res;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}

/*
void dfs(int v, int h,  int c) {
	used[v] = c;
	d[v] = h;
	mx_up[v] = 2e5 + 228;
	for(auto i: G[v]) {
		if (who.count(c))
			c = who[c];
		if (used[i] == -1)
			dfs(i, h + 1, c);
		// if (who.count(used[i]))
		// 	used[i] = who[used[i]];
		else if (used[i] != -1 && used[i] != c) {
			for(auto i: ans[c]) 
				ans[used[i]].push_back(i);
			ans[c].clear();
			who[c] = used[i];
			c = used[i];
		}
		mx_up[v] = min(mx_up[v], d[i]);
		if (used[i] != -1)
			mx_up[v] = min(mx_up[v], mx_up[i]);
	}
	if (who.count(c))
		c = who[c];
	if (mx_up[v] <= h)
		ans[c].push_back(v);
}

signed main() {
	setup();
	fill(used, used + N, -1);
	
	int n;
	cin >> n;
	vector<int> c(n);
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		G[i].push_back(a - 1);
	}
	int res = 0;
	for(int i = 0; i < n; ++i) {
		if (used[i] == -1) {
			ans.push_back(vector<int> ());
			dfs(i, 0, ans.size() - 1);
		}
	}
	for(auto i: ans) {
		cout << "MEOW:";
		int mn = 1e9;
		for(auto j: i) {
			cout << j << ' ';
			mn = min(mn, c[j]);
		}
		cout << '\n';
		if (mn != 1e9)
			res += mn;
	}
	cout << res;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}
*/