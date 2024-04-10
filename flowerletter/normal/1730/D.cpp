#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		string s, t;
		int n, flag = 1;
		cin >> n >> s >> t;
		map<pair<char, char>, int> mp;
		deque<int> q;
		for(int i = 0; i < n; i ++) {
			if(s[i] > t[n - 1 - i]) swap(s[i], t[n - 1 - i]);
			if(mp.count({s[i], t[n - 1 - i]})) mp.erase({s[i], t[n - 1 - i]});
			else mp[{s[i], t[n - 1 - i]}] = i;
		}
		for(auto [x, y] : mp) flag &= x.first == x.second;
		flag &= mp.size() <= 1;
		cout << (flag ? "Yes\n" : "No\n");
	}
	return 0;
}