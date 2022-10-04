#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

vector <vector <int>> g;
vector <int> p1;
vector <int> p2;
int x, y;

void dfs1(int u, int pp) {
	p1[u] = pp;
	for (auto v : g[u]) {
		if (v != pp) dfs1(v, u);
	}
}

void dfs2(int u, int pp) {
	p2[u] = pp;
	for (auto v : g[u]) {
		if (v != pp) dfs2(v, u);
	}
}

ll ans = 0;

int dfs_count(int u, int p) {
	if (u == -1) return 0;
	int cnt = 0;
	for (auto v : g[u]) {
		if (v != p) {
			cnt += dfs_count(v, u);
		}
	}
	return cnt + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n >> x >> y;
	--x, --y; 
	g.resize(n);
	p1.resize(n, -1);
	p2.resize(n, -1);
	for (int i = 0; i + 1 < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(x, -1);
	dfs2(y, -1);
	ll cnt1 = dfs_count(x, p2[x]);
	ll cnt2 = dfs_count(y, p1[y]);
	ll ans = (ll)n * (n - 1);
	ans -= cnt1 * cnt2;
	cout << ans << '\n';
}