#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 998244353;
const int N = 222222;
vector<int> a[N];
long long dp[N];

void dfs(int v, int p = -1) {
	dp[v] = 1;
	int cur = 2;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		dp[v] = dp[v] * dp[x] % mod;
		dp[v] = dp[v] * (cur++) % mod;
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int r = 0;
	while ((int)a[r].size() != 1) {
		++r;
	}
	dfs(r);

	// cerr << r << "\n";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << dp[i] << " ";
	// }
	// cerr << "\n";

	cout << dp[a[r][0]] * n % mod << "\n";

	return 0;
}