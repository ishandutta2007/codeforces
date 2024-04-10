#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 1; i <= k; i++){
		int x = i;
		vector<int> ans;
		for(int j = n; j >= 1; j--){
			if(x >= j){
				ans.emplace_back(a[j - 1]);
				x -= j;
			}
		}
		cout << ans.size() << " ";
		for(auto x : ans){
			cout << x << " ";
		}
		cout << '\n';
	}

	return 0;
}