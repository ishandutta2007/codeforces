#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, k;
int dp[100007];
int ma[100007];
int t[100007];
int x[100007];
int y[100007];

inline int get_dist(int v, int u) {
	return abs(x[v] - x[u]) + abs(y[v] - y[u]);
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> x[i] >> y[i];
	}

	dp[0] = 0;
	ma[0] = 0;
	t[0] = 0;
	x[0] = 1;
	y[0] = 1;
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		dp[i] = -1;
		for (int j = i - 1; j >= 0; --j) if (dp[j] >= 0) {
			if (t[i] - t[j] > 1007) {
				dp[i] = max(dp[i], ma[j] + 1);
				break;
			}
			if (get_dist(i, j) <= t[i] - t[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		ma[i] = max(ma[i - 1], dp[i]);
		ans = max(ans, dp[i]);
	}


	cout << ans;
}