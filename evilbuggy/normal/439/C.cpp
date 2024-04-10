#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int k; cin >> k;
	int p; cin >> p;
	vector<int> eve, odd;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x&1)odd.emplace_back(x);
		else eve.emplace_back(x);
	}
	int ne = (int)eve.size();
	int no = (int)odd.size();
	if((k - p)%2 != no%2 || k - p > no || (k - p) + (no - k + p)/2 + ne < k){
		cout << "NO" << '\n';
		exit(0);
	}
	vector<vector<int> > ans(k);
	for(int i = 0; i < k - p; i++){
		ans[i].emplace_back(odd.back());
		odd.pop_back();
	}
	for(int i = 0; i < p; i++){
		if(!eve.empty()){
			ans[i + k - p].emplace_back(eve.back());
			eve.pop_back();
		}else{
			ans[i + k - p].emplace_back(odd.back()); odd.pop_back();
			ans[i + k - p].emplace_back(odd.back()); odd.pop_back();
		}
	}
	while(!eve.empty()){
		ans[0].emplace_back(eve.back()); eve.pop_back();
	}
	while(!odd.empty()){
		ans[0].emplace_back(odd.back()); odd.pop_back();
	}
	cout << "YES" << '\n';
	for(auto x : ans){
		cout << x.size() << ' ';
		for(auto y : x){
			cout << y << ' ';
		}
		cout << '\n';
	}

	return 0;
}