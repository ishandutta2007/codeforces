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
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3")

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

const int MOD = 1e9 + 7;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1) 
		return a * pow(a, b - 1) % MOD;
	int z = pow(a, b / 2);
	return z * z % MOD;
}

int fact(int n) {
	int ans = 1;
	for(int i = 1; i <= n; ++i)
		ans = ans * i % MOD;
	return ans;
}

const int N = 505;

int dp[N][N];

signed main() {
	setup();
	for(int i = 0; i < N; ++i)
		fill(dp[i], dp[i] + N, 0);
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		sum1 += a[i].first;
		sum2 += a[i].second;
	}
	for(int i = 1; i < k; ++i) {
		if (a[0].first < i || a[0].second < (k - i))
			continue;
		dp[0][(a[0].first - i) % k] = 1 + (a[0].first - i) / k + (a[0].second - (k - i)) / k;
		// cout << ((a[0].first - i) % k + k) % k << ' ';
	}
	dp[0][a[0].first % k] = true;
	for(int i = 1; i < n; ++i) {
		// sum1 += a[i].first;
		// sum2 += a[i].second;
		for(int j = 0; j < k; ++j) {
			if (!dp[i - 1][j])
				continue;
			// cout << (j + a[i].first) % k << ' ';
			// int ost = ((sum1 + sum2 - (j) % k + k) % k;
			dp[i][(j + a[i].first) % k] = true;
			for(int p = 1; p < k; ++p) {
				if (a[i].first < p || a[i].second < (k - p))
					continue;
				dp[i][((a[i].first + j - p) % k + k) % k] = true;
			}
		}
	}
	// cout << '\n';
	int ans = 0;
	// cout << sum1 << ' ' << sum2 << '\n';
	for(int i = 0; i < k; ++i) {
		// cout << dp[n - 2][i] << ' ';
		if (dp[n - 1][i]) {
			int ost = ((sum1 + sum2 - i) % k + k) % k;
			// cout << i << ':' << ost << ':' << (sum1 + sum2 << ' ';
			ans = max(ans, (sum1 + sum2 - i - ost) / k);
		}	
	}
	cout << ans << '\n';

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}