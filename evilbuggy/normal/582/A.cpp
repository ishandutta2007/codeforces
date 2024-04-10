#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	multiset<int> st;
	for(int i = 0; i < n*n; i++){
		int x;
		cin >> x;
		st.insert(x);
	}
	vector<int> ans;
	while(!st.empty()){
		int x = *st.rbegin();
		st.erase(st.find(x));
		for(auto y : ans){
			st.erase(st.find(__gcd(x, y)));
			st.erase(st.find(__gcd(x, y)));
		}
		ans.emplace_back(x);
	}
	for(auto x : ans){
		cout << x << " ";
	}
	cout << '\n';

	return 0;
}