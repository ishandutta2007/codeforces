#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, p;
	cin >> n >> p >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end(), greater<pair<int, int>>());
	vector<vector<int>> s(n, vector<int>(p));
	for (int i = 0; i < n; ++i) for(int j = 0; j < p; ++j) cin >> s[i][j];
	vector<vector<long long>> dp(n + 1, vector<long long>(1<<p));
	for (int i = n - 1; i >= 0; --i) {
		for(int j = 0; j < (1<<p); ++j) {
			int ct = 0;
			for (int q = 1, ind = 0; q < (1<<p); q<<=1, ++ind) if(j&q) ++ct;
			dp[i][j] = dp[i + 1][j] + (ct + k > i ? a[i].first : 0);
			for (int q = 1, ind = 0; q < (1<<p); q<<=1, ++ind) {
				if (!(q&j)) {
				  if (i == n - 1) {
				  	if (j + q + 1 == 1<<p) dp[i][j] = s[a[i].second][ind]; 
				  	else dp[i][j] = -1e18;
				  }
					else dp[i][j] = max(dp[i][j], dp[i + 1][j + q] + s[a[i].second][ind]);
				}
			}
		}
	}
	cout << dp[0][0];
}