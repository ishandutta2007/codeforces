#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, r;
	cin >> n >> r;
	vector<int> lo;
	vector<int> hi;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x){
			lo.emplace_back(max(1, i - r + 1));
			hi.emplace_back(min(n, i + r - 1));
		}
	}
	int m = (int)lo.size();
	vector<int> dp(m, m + 1);
	for(int i = 0; i < m; i++){
		if(lo[i] == 1){
			dp[i] = 1;
		}
		for(int j = 0; j < i; j++){
			if(lo[i] <= hi[j] + 1){
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = -1;
	for(int i = 0; i < m; i++){
		if(hi[i] == n && dp[i] != m + 1 && (ans == -1 || ans > dp[i])){
			ans = dp[i];
		}
	}
	cout << ans << '\n';

	return 0;
}