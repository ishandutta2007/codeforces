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

const int L = 18;
const int N = 111111;
vector<int> a[N];
int par[L][N];
long long g[L][N];
int level[N];

const int mod = 1000000007;

void dfs(int v, int p = -1) {
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		par[0][x] = v;
		level[x] = level[v] + 1;
		dfs(x, v);
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	assert(gcd(0, 0) == 0);
	assert(gcd(0, 100) == 100);
	assert(gcd(100, 0) == 100);

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &g[0][i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	par[0][0] = 0;
	dfs(0);

	for (int i = 1; i < L; ++i) {
		for (int j = 0; j < n; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
			g[i][j] = gcd(g[i - 1][j], g[i - 1][par[i - 1][j]]);
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (g[L - 1][i] == 0) {
			continue;
		}
		int p = i;
		for (int j = L - 1; j >= 0; --j) {
			if (g[j][p] == 0) {
				p = par[j][p];
			}
		}
		if (g[0][p] == 0) {
			continue;
		}
		long long cur = g[0][p];
		while (cur != g[L - 1][i]) {
			int oldlvl = level[p];
			for (int j = L - 1; j >= 0; --j) {
				if (gcd(cur, g[j][p]) == cur) {
					p = par[j][p];
				}
			}
			ans += cur % mod * (oldlvl - level[p]) % mod;
			cur = gcd(cur, g[0][p]);
		}
		ans += cur % mod * (level[p] + 1) % mod;
	}

	cout << ans % mod << "\n";

	return 0;
}