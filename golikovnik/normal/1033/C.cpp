#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

const int N = 1e5 + 20;
vector<int> graph[N];
int a[N];
int ans[N];

int dfs(int u) {
	if (ans[u] >= 0) {
		return ans[u];
	}
	bool ok = 0;
	for (int v: graph[u]) {
		if (ans[v] < 0) {
			dfs(v);
		}
		ok |= (ans[v] == 0);
	}
	ans[u] = ok;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int delta = a[i]; delta <= n; delta += a[i]) {
			if (i + delta <= n && a[i + delta] > a[i]) {
				graph[i].push_back(i + delta);
			}
			if (i - delta > 0 && a[i - delta] > a[i]) {
				graph[i].push_back(i - delta);
			}
		}
	}
	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= n; ++i) {
		if (ans[i] < 0) {
			dfs(i);
		}
		cout << (ans[i] ? "A" : "B");
	}
	return 0;
}