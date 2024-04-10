#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	string s;
	cin >> s;
	vector<int> cnt(26);
	for (char c : s) {
		cnt[c - 'a'] += 1;
	}
	if (*min_element(all(s)) == *max_element(all(s))) {
		cout << s << "\n";
		return;
	}
	if (auto it = find(all(cnt), 1); it != cnt.end()) {
		char c = 'a' + (it - cnt.begin());
		s.erase(find(all(s), c));
		sort(all(s));
		s = c + s;
		cout << s << "\n";
		return;
	}
	char c = *min_element(all(s));
	string t(1, c);
	cnt[c - 'a'] -= 1;
	int n = s.length();
	if (cnt[c - 'a'] <= n - cnt[c - 'a']) {
		t += c;
		cnt[c - 'a'] -= 1;
	} else {
		int i = c - 'a' + 1;
		while (cnt[i] == 0) {
			++i;
		}
		t += (char)('a' + i);
		cnt[i] -= 1;
	}
	n -= 2;

	if (t[0] == t[1]) {
		int i = c - 'a' + 1;
		while (cnt[c - 'a']) {
			while (!cnt[i]) {
				++i;
			}
			t += (char)('a' + i);
			cnt[i] -= 1;
			t += c;
			cnt[c - 'a'] -= 1;
		}
		while (i < 26) {
			t += string(cnt[i], 'a' + i);
			++i;
		}
	} else {
		if (cnt[t[0] - 'a'] + cnt[t[1] - 'a'] == n) {
			t += string(cnt[t[1] - 'a'], t[1]);
			t += string(cnt[t[0] - 'a'], t[0]);
		} else {
			t += string(cnt[c - 'a'], c);
			cnt[c - 'a'] = 0;
			int i = 0;
			while (cnt[i] == 0 || i == c - 'a' || i == t[1] - 'a') {
				++i;
			}
			t += (char)('a' + i);
			cnt[i] -= 1;
			for (int i = 0; i < 26; ++i) {
				t += string(cnt[i], 'a' + i);
			}
		}
	}
	cout << t << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}