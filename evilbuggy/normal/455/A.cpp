#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

long long f[maxn], dp[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	memset(f, 0, sizeof(f));
	for(int i = 0; i < n; i++){
		int x; cin >> x; f[x]++;
	}
	dp[1] = f[1];
	for(int i = 2; i < maxn; i++){
		if(!f[i]){
			dp[i] = dp[i - 1];
		}else{
			dp[i] = i*f[i] + dp[i - 2];
			if(f[i - 1]){
				if(i == 2){
					dp[i] = max(dp[i], (i - 1)*f[i - 1]);
				}else{
					dp[i] = max(dp[i], (i - 1)*f[i - 1] + dp[i - 3]);
				}
			}
		}
	}
	cout << dp[maxn - 1] << '\n';

	return 0;
}