#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s, t;
	cin >> n >> s >> t;
	vector<int> a;
	for (int i = 0; i < n; ++i) if (s[i] != t[i]) a.push_back(s[i] - t[i] + 1);
	n = a.size();
	if (accumulate(a.begin(), a.end(), 0) != a.size()) return cout << -1, 0;
	int ans = 0;  
	for (int i = 0; i < 3; i += 2) {
		int ct = 0;
		for (int el : a) {
			if (i == el) ++ct;
			else --ct;
			ans = max(ct, ans);
			ct += ct < 0;
		}
	}
	cout << ans << '\n';
}