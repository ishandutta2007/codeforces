#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	vector<int> ans;
	for(int i = 0; i < n; i++){
		int sz = (int)ans.size();
		while(sz >= 2){
			if(ans[sz - 2] < ans[sz - 1] && ans[sz - 1] < p[i]){
				ans.pop_back(); sz--; continue;
			}
			if(ans[sz - 2] > ans[sz - 1] && ans[sz - 1] > p[i]){
				ans.pop_back(); sz--; continue;
			}
			break;
		}
		ans.push_back(p[i]);
	}
	cout << (int)ans.size() << '\n';
	for(int i = 0; i < (int)ans.size(); i++){
		cout << ans[i] << ' ';
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