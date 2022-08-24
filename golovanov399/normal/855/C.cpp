#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

vector<long long> mult(const vector<long long>& a, const vector<long long>& b) {
	int n = a.size();
	vector<long long> c(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; i + j < n; ++j) {
			c[i + j] += 1ll * a[i] * b[j] % mod;
		}
	}
	for (int i = 0; i < n; ++i) {
		c[i] %= mod;
	}
	return c;
}

vector<long long> add(vector<long long> a, const vector<long long>& b) {
	for (int i = 0; i < (int)a.size(); ++i) {
		a[i] += b[i];
		if (a[i] >= mod) {
			a[i] -= mod;
		}
	}
	return a;
}

vector<long long> shift(vector<long long> a) {
	for (int i = (int)a.size() - 1; i > 0; --i) {
		a[i] = a[i - 1];
	}
	a[0] = 0;
	return a;
}

const int N = 111111;
vector<long long> dp[3][N];
vector<int> a[N];

int m, k;

void dfs(int v, int p = -1) {
	dp[2][v][0] = m - k;
	dp[1][v][0] = 1;
	dp[0][v][0] = k - 1;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		auto tmp = add(dp[0][x], dp[2][x]);
		dp[2][v] = mult(dp[2][v], tmp);
		dp[0][v] = mult(dp[0][v], add(dp[1][x], tmp));
		dp[1][v] = mult(dp[1][v], dp[0][x]);
	}
	dp[1][v] = shift(dp[1][v]);
}

int main() {
	int n = nxt();
	m = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	k = nxt();
	int x = nxt() + 1;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j].assign(x, 0);
		}
	}

	dfs(0);

	auto q = add(dp[0][0], add(dp[1][0], dp[2][0]));
	cout << accumulate(all(q), 0ll) % mod << "\n";

	return 0;
}