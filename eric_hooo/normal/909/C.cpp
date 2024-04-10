#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
	int N;
	cin >> N;
	vector<int> dp(N + 1);
	dp[0] = 1;
	int cnt = 0;
	for (int t = 0; t < N; t++){
		string s; cin >> s;
		if (s == "s") {
			vector<int> sum(N + 2);
			for (int x = N; x >= 0; x--){
				sum[x] = (sum[x + 1] + dp[x]) % MOD;
			}
			for (int x = 0; x <= N; x++){
				dp[x] = 0;
			}
			for (int x = 0; x <= N; x++){
				if (x + cnt <= N) dp[x + cnt] = sum[x];
			}
			cnt = 0;
		}
		if (s == "f") cnt++;
	}
	int ans = 0;
	for (int x = 0; x <= N; x++){
		ans = (ans + dp[x]) % MOD;
	}
	cout << ans << endl;
}