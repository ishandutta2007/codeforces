#include <bits/stdc++.h>
using namespace std;

const int logn = 31;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		int k; cin >> k;
		vector<int> cnt(logn);
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			for(int j = 0; j < logn; j++){
				if((x >> j) & 1)cnt[j]++;
			}
		}
		int ans = 0;
		for(int i = logn - 1; i >= 0; i--){
			if(n - cnt[i] <= k){
				k -= (n - cnt[i]);
				ans ^= (1 << i);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}