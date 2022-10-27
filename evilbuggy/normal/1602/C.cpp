#include <bits/stdc++.h>
using namespace std;

const int K = 30;

void solve(){
	int n;
	cin >> n;
	vector<int> cnt(K);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int j = 0; j < K; j++){
			if((x >> j) & 1)cnt[j]++;
		}
	}
	int ans = 0;
	for(int j = 0; j < K; j++){
		ans = __gcd(ans, cnt[j]);
	}
	if(ans == 0){
		for(int i = 1; i <= n; i++){
			cout << i << " ";
		}
		cout << '\n';
		return;
	}
	for(int k = 1; k <= n; k++){
		if(ans%k == 0)cout << k << ' ';
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}