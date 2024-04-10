#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> ans;
	for(int i = 0; i < n; i++){
		int j = -1;
		for(int k = i; k < n; k++){
			if(s[k] == t[i]){
				j = k;
				break;
			}
		}
		if(j == -1){
			cout << -1 << '\n';
			exit(0);
		}
		while(j > i){
			swap(s[j], s[j - 1]);
			ans.emplace_back(j);
			j--;
		}
	}
	cout << ans.size() << '\n';
	for(auto x : ans){
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}