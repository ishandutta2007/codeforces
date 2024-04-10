#include <bits/stdc++.h>
using namespace std;

void compute(int n, deque<int> &ans){
	if(n == 1){
		ans.emplace_back(1);
		return;
	}else if(n == 2){
		ans.emplace_back(1);
		ans.emplace_back(2);
		return;
	}else if(n == 3){
		ans.emplace_back(1);
		ans.emplace_back(1);
		ans.emplace_back(3);
		return;
	}
	compute(n/2, ans);
	for(auto &x : ans){
		x *= 2;
	}
	for(int i = 1; i <= n; i += 2){
		ans.emplace_front(1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	deque<int> ans;
	compute(n, ans);
	for(auto x : ans){
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}