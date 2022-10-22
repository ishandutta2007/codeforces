#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main () {
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'a']++;
	}
	int now = 0;
	for (int i = 25; i >= now; i--) {
		if (cnt[i] & 1) {
			while (now < i && (cnt[now] % 2 == 0)) now++;
			if (now == i) break;
			cnt[now]++, cnt[i]--;
		}
	}
	int pos = -1;
	for (int i = 0; i < 25; i++) {
		if (cnt[i] & 1) {
			assert(pos == -1);
			pos = i;
		}
	}
	string ans;
	for (int i = 0; i < 26; i++) {
		cnt[i] /= 2;
		while (cnt[i]--) ans.push_back(char(i + 'a'));
	}
	string tmp = ans; reverse(tmp.begin(), tmp.end());
	if (~pos) ans.push_back(char(pos + 'a'));
	cout << ans + tmp << endl;
	return 0;
}