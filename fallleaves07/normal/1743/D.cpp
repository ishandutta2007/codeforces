#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n;
	string s, t;
	cin >> n >> s;
	int st = 0, len = 0;
	for (int j = 0; j < n; j++) {
		if (s[j] != '0') {
			t = s.substr(j);
			break;
		}
	}
	if (t.length() == 0) {
		cout << "0\n";
		return 0;
	}
	vector<int> loc0;
	for (int i = 0; i < (int)t.length(); i++) {
		if (t[i] == '0') {
			if (!st) {
				st = i, len = t.length() - i;
			}
			loc0.push_back(i - st);
		}
	}
	if (loc0.empty()) {
		cout << s << '\n';
		return 0;
	}
	string ans = t;
	int mx = -1;
	for (int i = 0; i + len <= n; i++) {
		int l = (int)loc0.size();
		for (int j = 0; j < (int)loc0.size(); j++) {
			if (s[i + loc0[j]] == '0') {
				l = j;
				break;
			}
		}
		mx = max(mx, l);
	}
	for (int i = 0; i + len <= n; i++) {
		int l = (int)loc0.size();
		for (int j = 0; j < (int)loc0.size(); j++) {
			if (s[i + loc0[j]] == '0') {
				l = j;
				break;
			}
		}
		if (l == mx) {
			string now = ans;
			for (int j = 0; j < (int)loc0.size(); j++) {
				now[loc0[j] + st] = s[i + loc0[j]];
			}
			ans = max(ans, now);
		}
	}
	cout << ans << '\n';
    return 0;
}