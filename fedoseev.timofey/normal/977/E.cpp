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

const int N = 2e5 + 7;

int deg[N];
int p[N];

int find(int u) {
	if (u == p[u]) return u;
	else return p[u] = find(p[u]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) p[i] = i;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		p[find(v)] = find(u);
		++deg[u], ++deg[v];
	}
	vector <bool> good(n, false);
	for (int i = 0; i < n; ++i) {
		good[find(i)] = 1;
	}
	for (int i = 0; i < n; ++i) {
		if (deg[i] != 2) good[find(i)] = 0;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) ans += good[i];
	cout << ans << '\n';
}