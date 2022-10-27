#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > generate(int n){
	if(n <= 0)return {};
	if(n%3 != 2){
		vector<pair<int, int> > ret = generate(n - 1);
		ret.emplace_back(n, n);
		return ret;
	}
	int k = (n - 2)/3;
	vector<pair<int, int> > ret;
	for(int i = 1; i <= k + 1; i++){
		ret.emplace_back(i, k + 2 - i);
	}
	for(int i = k + 2; i <= 2*k + 1; i++){
		ret.emplace_back(i, n + 1 - i);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int> > ans = generate(n);
	cout << (int)ans.size() << '\n';
	for(auto x : ans){
		cout << x.first << " " << x.second << '\n';
	}

	return 0;
}