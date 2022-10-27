#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> r(n);
	long long cur = 0;
	for(int i = 0, l = -1; i < n; i++){
		while(l + 1 < n && cur + a[l + 1] <= k){
			cur += a[l + 1]; l++;
		}
		r[i] = l; cur -= a[i];
	}
	int ans = 0;
	vector<int> dp(n);
	for(int i = n - 1; i >= 0; i--){
		if(r[i] + 1 == n){
			dp[i] = 1;
		}else{
			dp[i] = dp[r[i] + 1] + 1;
		}
		if(dp[i] <= m){
			ans = n - i;
		}
	}
	cout << ans << '\n';

	return 0;
}