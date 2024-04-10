#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int, int> > a;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			a.emplace_back(x, i);
		}
		vector<int> ans(n);
		long long totdist = 0;
		sort(a.rbegin(), a.rend());
		for(int i = 0; i < n; i++){
			if(i&1){
				ans[a[i].second] = -(i/2) - 1;
			}else{
				ans[a[i].second] = +(i/2) + 1;
			}
			totdist += 2LL*abs(ans[a[i].second])*a[i].first;
		}
		cout << totdist << '\n';
		cout << 0 << " ";
		for(int i = 0; i < n; i++){
			cout << ans[i] << " ";
		}
		cout << '\n';
	}

	return 0;
}