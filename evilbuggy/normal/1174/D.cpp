#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	vector<int> d;
	for(int i = 0; i < (1 << n); i++){
		if(i < (i^x))d.emplace_back(i);
	}
	vector<int> ans;
	for(int i = 1; i < (int)d.size(); i++){
		ans.emplace_back(d[i]^d[i - 1]);
	}
	cout << ans.size() << '\n';
	for(auto x : ans){
		cout << x << " ";
	}
	cout << '\n';

	return 0;
}