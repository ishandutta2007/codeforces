#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
const int N = 1000005;
long long dp[N], sum[N], fac[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	dp[0] = 1; sum[0] = 1;
	dp[1] = 1; sum[1] = 2;
	memset(fac, 0, sizeof(fac));
	for(int i = 2; i <= n; i++){
		for(int j = i; j <= n; j += i){
			fac[j]++;
		}
	}
	for(int i = 2; i <= n; i++){
		dp[i] = sum[i - 1] + fac[i];
		sum[i] = sum[i - 1] + dp[i];
		if(dp[i] >= mod)dp[i] -= mod;
		if(sum[i] >= mod)sum[i] -= mod;
	}
	cout << dp[n] << '\n';

	return 0;
}