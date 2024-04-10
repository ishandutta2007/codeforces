#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> ans;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			int y = 1;
			while(y <= x)y <<= 1;
			y >>= 1;
			ans.push_back(y);
		}
		for(auto x : ans){
			cout << x << ' ';
		}
		cout << '\n';
	}

	return 0;
}