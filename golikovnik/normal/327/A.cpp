#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];
	int sum = accumulate(all(a), 0);
	vector<vector<int>> dp(n, vector<int>(n));
	rep(i, 0, n) {
		rep(j, i, n) {
			if (i == j) {
				dp[i][j] = sum + 1 - a[i] - a[i];
				continue;
			}
			dp[i][j] = dp[i][j-1] + 1 - a[j] - a[j];
		}
	}
	int res = 0;
	rep(i, 0, n) {
		rep(j, i, n) {
			res = max(res, dp[i][j]);
		}
	}
	cout << res;
	return 0;
}