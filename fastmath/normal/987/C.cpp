#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3007;
const int INF = 1e9 + 7;

int dp1[MAXN], dp2[MAXN], dp3[MAXN];
int a[MAXN], c[MAXN];
     	
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> c[i];

	for (int i = 0; i < MAXN; ++i) dp1[i] = dp2[i] = dp3[i] = INF;

	for (int i = 0; i < n; ++i) dp1[i] = c[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
		 	if (a[j] < a[i]) dp2[i] = min(dp2[i], dp1[j] + c[i]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
		 	if (a[j] < a[i]) dp3[i] = min(dp3[i], dp2[j] + c[i]);
		}
	}

	int ans = INF;
	for (int i = 0; i < n; ++i) ans = min(ans, dp3[i]);

	if (ans == INF) cout << "-1\n";
	else cout << ans << '\n';
	return 0;
}