#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<vector<int> > a(n);
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			a[x - 1].emplace_back(i);
		}
		vector<int> ans(n);
		vector<int> excess;
		for(int i = 0; i < n; i++){
			if(a[i].size() < k){
				for(auto x : a[i]){
					excess.emplace_back(x);
				}
				continue;
			}
			for(int j = 0; j < k; j++){
				ans[a[i][j]] = j + 1;
			}
		}
		while(excess.size() >= k){
			for(int i = 0; i < k; i++){
				ans[excess.back()] = i + 1;
				excess.pop_back();
			}
		}
		for(int i = 0; i < n; i++){
			cout << ans[i] << " ";
		}
		cout << '\n';
	}

	return 0;
}