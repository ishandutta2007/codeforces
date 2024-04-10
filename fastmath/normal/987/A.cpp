#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	set <string> ans;
	ans.insert("purple");
	ans.insert("green");
	ans.insert("blue");
	ans.insert("orange");
	ans.insert("red");
	ans.insert("yellow");

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
	 	string s;
	 	cin >> s;
	 	ans.erase(s);
	}

	map <string, string> d;
	d["purple"] = "Power";
	d["green"] = "Time";
	d["blue"] = "Space";
	d["orange"] = "Soul";
	d["red"] = "Reality";
	d["yellow"] = "Mind";

	cout << ans.size() << '\n';
	for (string s : ans) cout << d[s] << '\n';

	return 0;
}