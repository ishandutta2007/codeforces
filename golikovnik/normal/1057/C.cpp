#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

const int N = 55, K = 3000;

int dp[N][K];

const int INF = 1e6;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n, start, k;
	cin >> n >> start >> k;
	--start;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(all(a));
	string colors; cin >> colors;
	memset(dp, INF, sizeof(dp));
	auto remin = [&](int &x, int y) {
		if (x > y) x = y;
	};
	for (int i = n - 1; i >= 0; --i) {
		int ii = a[i].second;
		dp[ii][a[i].first] = 0;
		for (int j = i + 1; j < n; ++j) {
			int jj = a[j].second;
			if (colors[ii] != colors[jj] && a[j].first > a[i].first) {
				for (int s = 0; s + a[i].first < K; ++s) {
					remin(dp[ii][s + a[i].first], dp[jj][s] + abs(jj - ii));
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < n; ++i) {
		for (int s = k; s < K; ++s) {
			ans = min(ans, abs(i - start) + dp[i][s]);
		}
	}
	cout << (ans < INF ? ans : -1) << "\n";
	return 0;
}