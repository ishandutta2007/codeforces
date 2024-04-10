#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

int main() {
	int n = nxt();
	int N = 1 << n;
	vector<vector<long double>> a(N, vector<long double>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			a[i][j] = nxt() * 0.01;
		}
	}

	vector<vector<long double>> dp(N + N, vector<long double>(N, 0.0));
	for (int i = 0; i < N; ++i) {
		dp[N + i][i] = 1.0;
	}
	vector<vector<long double>> prob(N + N, vector<long double>(N, 0.0));
	for (int i = 0; i < N; ++i) {
		prob[N + i][i] = 1.0;
	}

	for (int v = N - 1; v > 0; --v) {
		int q = 1 << (31 - __builtin_clz(v));
		int l = (v - q) * N / q;
		int r = l + N / q;
		int m = (l + r) / 2;

		for (int i = l; i < m; ++i) {
			for (int j = m; j < r; ++j) {
				dp[v][i] += (prob[v + v][i] * prob[v + v + 1][j] * a[i][j]) * (N / q);
				dp[v][j] += (prob[v + v][i] * prob[v + v + 1][j] * a[j][i]) * (N / q);

				prob[v][i] += prob[v + v][i] * prob[v + v + 1][j] * a[i][j];
				prob[v][j] += prob[v + v][i] * prob[v + v + 1][j] * a[j][i];
			}
		}

		auto lmx = *max_element(all(dp[v + v]));
		auto rmx = *max_element(all(dp[v + v + 1]));
		for (int i = l; i < m; ++i) {
			dp[v][i] += dp[v + v][i] + rmx;
		}
		for (int i = m; i < r; ++i) {
			dp[v][i] += dp[v + v + 1][i] + lmx;
		}
	}

	cout << setprecision(10) << fixed;
	cout << (*max_element(all(dp[1])) - N) / 2 << "\n";

	return 0;
}