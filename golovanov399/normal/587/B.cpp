#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

int main(){

	int n, k;
	long long l;
	cin >> n >> l >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = nxt();

	vector<pair<int, int>> b(n);
	for (int i = 0; i < n; i++)
		b[i] = {a[i], i};
	sort(all(b));

	vector<int> pr(n);
	pr[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--){
		pr[i] = (b[i].first == b[i + 1].first) ? pr[i + 1] : i;
	}

	vector<vector<int>> dp(k, vector<int>(n, 0));
	for (int i = 0; i < n; i++){
		dp[0][i] = i + 1;
	}
	for (int i = 1; i < k; i++){
		for (int j = 0; j < n; j++){
			dp[i][j] = dp[i - 1][pr[j]];
			if (j)
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
		}
	}

	long long ans = 0;
	for (int _ = 0; _ < k; _++){
		if (l <= 1ll * n * _)
			break;
		ans += 1ll * ((l / n) - _) % mod * dp[_][n - 1] % mod;
		for (int i = 0; i < n; i++){
			if (b[i].second < l % n){
				ans += dp[_][i];
				if (i > 0)
					ans += mod - dp[_][i - 1];
			}
		}
		ans %= mod;
	}

	cout << ans % mod << "\n";

	return 0;
}