#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	long long ans = (long long)1e18;
	int mx = *max_element(h.begin(), h.end());
	
	for(int s = mx; s <= mx + 1; s++){
		long long cnt1 = 0;
		long long cnt2 = 0;
		for(int i = 0; i < n; i++){
			int req = s - h[i];
			cnt2 += req/2;
			cnt1 += req%2;
		}
		if(cnt2 < cnt1){
			ans = min(ans, 2*cnt1 - 1);
			continue;
		}
		long long x = (cnt2 - cnt1)/3 - 5;
		for(int i = 0; i < 10; i++){
			long long ncnt1 = cnt1 + 2*x;
			long long ncnt2 = cnt2 - x;
			if(ncnt1 >= 0 && ncnt2 >= 0){
				ans = min(ans, max(2*ncnt2, 2*ncnt1 - 1));
			}
			x++;
		}
	}
	ans = max(ans, 0LL);
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