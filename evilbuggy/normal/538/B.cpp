#include <bits/stdc++.h>
using namespace std;

inline int get(int n){
	int ret = 0, prd = 1;
	while(n){
		if(n%10 != 0){
			ret += prd;
		}
		n /= 10;
		prd *= 10;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> ans;
	while(n){
		ans.emplace_back(get(n));
		n -= ans.back();
	}
	cout << ans.size() << '\n';
	for(auto x : ans){
		cout << x << " ";
	}
	cout << '\n';

	return 0;
}