#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll n, r1, r2, r3, d;
ll a[1000007];
ll dp[1000007];

ll score_one(int v) {
	--v;
	ll ans = a[v] * r1 + r3;
	ll ans2 = a[v] * r1 + r1 + 2 * d + r1;
	ll ans3 = r2 + 2 * d + r1;
	return min({ans, ans2, ans3});
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r1 >> r2 >> r3 >> d;

	for (int i = 0; i < n; ++i) cin >> a[i];

	dp[0] = -d;
	dp[1] = score_one(1);

	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + score_one(i) + d;
		ll res = dp[i - 2] + 4 * d;

		res += 2 * r1;
		res += min(r2, r1 * a[i - 2] + r1);
		res += min(r2, r1 * a[i - 1] + r1);

		dp[i] = min(dp[i], res);

		res = dp[i - 2] + 4 * d;

		res += r1;
		res += min(r2, r1 * a[i - 2] + r1);
		res += r1 * a[i - 1] + r3;

		dp[i] = min(dp[i], res);
	}

	ll ans = dp[n];

	ll res = dp[n - 2] + 3 * d;

	res += r1;
	res += min(r2, r1 * a[n - 2] + r1);
	res += r1 * a[n - 1] + r3;

	ans = min(ans, res);


	cout << ans;
}