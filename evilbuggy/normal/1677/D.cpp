#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void solve(){
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = 1;
	for(int i = 0; i < n; i++){
		if(i >= n - k){
			if(a[i] > 0){
				cout << 0 << '\n';
				return;
			}
		}else{
			if(a[i] == 0){
				ans = 1LL*ans*(k + 1)%mod;
			}else if(a[i] == -1){
				ans = 1LL*ans*(i + k + 1)%mod;
			}
		}
	}
	for(int i = 0; i < k; i++){
		ans = 1LL*ans*(i + 1)%mod;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}