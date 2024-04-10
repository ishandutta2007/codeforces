#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> l(n);
	vector<int> r(n);
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
	}
	vector<int> ans;
	for(int i = 1; i <= m; i++){
		bool flg = true;
		for(int j = 0; j < n; j++){
			if(l[j] <= i && i <= r[j])flg = false;
		}
		if(flg)ans.emplace_back(i);
	}
	cout << ans.size() << '\n';
	for(auto x : ans){
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}