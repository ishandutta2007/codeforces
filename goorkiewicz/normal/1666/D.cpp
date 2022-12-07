#include<bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		string s, t;
		cin >> s >> t;
		int n = s.length();

		int cnt[26] = {};
		for (auto c : t) cnt[c - 'A']++;

		string res;
		for (int i = n - 1; 0 <= i; i--) {
			if (cnt[s[i] - 'A'] > 0) {
				res.push_back(s[i]);
				cnt[s[i] - 'A']--;
			}
		}
		reverse(res.begin(), res.end());

		if (res == t && count(cnt, cnt + 26, 0) == 26) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}