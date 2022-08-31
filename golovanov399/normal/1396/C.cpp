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

const int N = 1011111;
long long dp[N][5];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), r1 = nxt(), r2 = nxt(), r3 = nxt(), d = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<long long> immediate(n), anything(n);
	for (int i = 0; i < n; ++i) {
		immediate[i] = 1ll * r1 * a[i] + r3;
		anything[i] = min({immediate[i], 1ll * r1 * a[i] + 2 * r1, 1ll * r2 + r1});
	}
	immediate[n - 1] = min(immediate[n - 1], anything[n - 1] + 2 * d);
	// anything[n - 1] = 1e18;

	dp[0][0] = 0;
	dp[0][1] = 1e18;
	dp[0][2] = 1e18;
	dp[0][3] = 1e18;
	dp[0][4] = 1e18;
	for (int i = 0; i < n - 1; ++i) {
		dp[i + 1][0] = min(
			dp[i][0] + d + immediate[i],
			dp[i][3] + d + immediate[i]
		);
		dp[i + 1][1] = min({
			dp[i][0] + 2ll * d + anything[i],
			dp[i][3] + 2ll * d + anything[i],
		});
		dp[i + 1][2] = min(
			dp[i][1] + 3ll * d + anything[i],
			dp[i][2] + 3ll * d + anything[i]
		);
		dp[i + 1][3] = min(
			dp[i][1] + 2ll * d + anything[i],
			dp[i][2] + 2ll * d + anything[i]
		);
		dp[i + 1][4] = min(
			dp[i][0] + 2ll * d + anything[i],
			dp[i][4] + 2ll * d + anything[i]
		);
		// cerr << dp[i + 1][0] << " " << dp[i + 1][1] << " " << dp[i + 1][2] << " " << dp[i + 1][3] << " " << dp[i + 1][4] << "\n";
	}
	cout << min(min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3], dp[n - 1][4]}) + immediate[n - 1], min(dp[n - 2][0], dp[n - 2][3]) + anything[n - 2] + anything[n - 1] + 3ll * d) << "\n";

	return 0;
}