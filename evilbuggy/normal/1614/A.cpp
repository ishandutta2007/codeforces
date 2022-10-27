#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, l, r, k;
		cin >> n >> l >> r >> k;

		vector<int> prices;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(l <= x && x <= r){
				prices.emplace_back(x);
			}
		}
		sort(prices.rbegin(), prices.rend());
		int answer = 0;
		while(!prices.empty()){
			if(k < prices.back())break;
			k -= prices.back();
			prices.pop_back();
			answer++;
		}
		cout << answer << '\n';
	}

	return 0;
}