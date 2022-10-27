#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(n <= 4 || k < n + 1){
		cout << -1 << '\n';
		return 0;
	}
	vector<int> path({a, c});
	set<int> st({a, b, c, d});
	for(int i = 1; i <= n; i++){
		if(!st.count(i))path.emplace_back(i);
	}
	path.emplace_back(d);
	path.emplace_back(b);
	for(auto x : path){
		cout << x << " ";
	}
	cout << '\n';
	for(int i : {0, n - 2}){
		swap(path[i], path[i + 1]);
	}
	for(auto x : path){
		cout << x << " ";
	}
	cout << '\n';

	return 0;
}