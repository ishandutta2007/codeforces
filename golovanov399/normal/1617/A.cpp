#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	string s, t;
	cin >> s >> t;
	int cur = 0;
	vector<int> cnt(26);
	for (char c : s) {
		cnt[c - 'a'] += 1;
	}
	string ans = "";
	for (int i = 0; i < (int)s.length(); ++i) {
		int j = 0;
		while (cnt[j] == 0 || (cur == 1 && j == t[cur] - 'a' && cnt[t[2] - 'a'])) {
			++j;
		}
		ans += (char)('a' + j);
		if (t[cur] - 'a' == j) {
			++cur;
		}
		cnt[j] -= 1;
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}