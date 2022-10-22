#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int minp[5000010];
int vis[5000010];
int dp[5000010];

void get_pre(){
	for (int i = 2; i <= 5000000; i++){
		if (vis[i]) continue;
		minp[i] = i;
		for (int j = i + i; j <= 5000000; j += i){
			if (vis[j] == 0) minp[j] = i;
			vis[j] = 1;
		}
	}
}

int main(){
	memset(minp, 0x3f, sizeof(minp));
	get_pre();
	int t, l, r; cin >> t >> l >> r;
	dp[1] = 0;
	for (int i = 2; i <= r; i++){
		dp[i] = (dp[i / minp[i]] + (1ll * i * (minp[i] - 1) / 2) % mod);
	}
	long long ans = 0;
	for (int i = r; i >= l; i--){
		ans = (ans * t + dp[i]) % mod;
	}
	cout << ans << endl;
	return 0;
}