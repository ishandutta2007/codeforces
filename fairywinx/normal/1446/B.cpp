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
#include <random>
#include <cmath>
#include <bitset>
#include <complex>

#include <algorithm>
// #define int long long 
#define SOLVE int t; cin >> t; while(t--) solve();
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3")

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

const int N = 5555;
const int C = 30;
const int INF = 1e9 + 228;

int dp[N][N];

int nxt1[N][C];
int nxt2[N][C];

void solve() {
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	{
		vector<int> lst(C, n);
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < C; ++j)
				nxt1[i][j] = lst[j];
			lst[a[i] - 'a'] = i;
		}
	}
	{
		vector<int> lst(C, m);
		for (int i = m - 1; i >= 0; --i) {
			for (int j = 0; j < C; ++j)
				nxt2[i][j] = lst[j];
			lst[b[i] - 'a'] = i;
		}
	}
	// cout << a << ' ' << b << '\n';

	for (int i = 0; i <= n; ++i)
		fill(dp[i], dp[i] + m + 1, -INF);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dp[i][j] = -2;
			if (a[i] == b[j])
				dp[i][j] += 4;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// cout << dp[i][j] << ':' << b[i] << ':' << nxt1[j][a[i] - 'a'] << ' ';
			ans = max(ans, dp[i][j]);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
			dp[nxt1[i][b[j + 1] - 'a']][j + 1] = max(dp[nxt1[i][b[j + 1] - 'a']][j + 1], dp[i][j] + 4 - 1 - (nxt1[i][b[j + 1] - 'a'] - i));
			dp[i + 1][nxt2[j][a[i + 1] - 'a']] = max(dp[i + 1][nxt2[j][a[i + 1] - 'a']], dp[i][j] + 4 - 1 - (nxt2[j][a[i + 1] - 'a'] - j));
		}
		// cout << '\n';
	}
	cout << ans << '\n';
}

signed main() {
	setup();
	// SOLVE;
	solve();
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s  ";
	#endif
}