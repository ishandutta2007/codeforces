#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, m;
	cin >> n >> k >> m;
	map<string, int> indMap;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		indMap[s] = i;
	}
	int a[n + 1];
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= k; i++){
		int sz;
		cin >> sz;
		vector<int> grp(sz);
		for(auto &x : grp){
			cin >> x;
		}
		int mn = (int)1e9 + 5;
		for(auto x : grp){
			mn = min(mn, a[x]);
		}
		for(auto x : grp){
			a[x] = mn;
		}
	}
	long long answer = 0;
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		answer += a[indMap[s]];
	}
	cout << answer << '\n';

	return 0;
}