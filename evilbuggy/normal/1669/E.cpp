#include <bits/stdc++.h>
using namespace std;

inline bool compare(string s, string t){
	if(s[0] == t[0])return s[1] != t[1];
	return s[1] == t[1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<string, int> mp;
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			mp[s]++;
		}
		long long ans = 0;
		for(auto x : mp){
			for(auto y : mp){
				if(compare(x.first, y.first))ans += 1LL*x.second*y.second;
			}
		}
		ans /= 2;
		cout << ans << '\n';
	}

	return 0;
}