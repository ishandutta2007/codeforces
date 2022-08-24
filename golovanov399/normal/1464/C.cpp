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

int main() {
	int n = nxt();
	long long t;
	cin >> t;
	string s;
	cin >> s;
	t -= (1 << (s[n - 1] - 'a'));
	t += (1 << (s[n - 2] - 'a'));
	vector<int> cnt(26);
	s = s.substr(0, n - 2);
	for (char c : s) {
		cnt[c - 'a'] += 1;
	}
	for (int i = 0; i < 26; ++i) {
		t += (long long)(cnt[i]) << i;
	}
	for (int i = 0; i < 25; ++i) {
		int tmp = cnt[i] % 2;
		if (cnt[i] && !tmp) {
			tmp = 2;
		}
		cnt[i + 1] += (cnt[i] - tmp) / 2;
		cnt[i] = tmp;
	}

	constexpr long long mask = (1ll << 26) - 1;
	function<void(int)> rec = [&](int i) {
		if (i == 25) {
			if (!(t & mask) && t >= 0 && t <= ((1ll * cnt[i]) << 26)) {
				cout << "Yes\n";
				exit(0);
			}
			return;
		}
		if (abs(t) & (1ll << (i + 1))) {
			if (!cnt[i]) {
				return;
			}
			t -= 1ll << (i + 1);
			rec(i + 1);
			t += 1ll << (i + 1);
		} else {
			rec(i + 1);
			if (cnt[i] >= 2) {
				t -= 2ll << (i + 1);
				rec(i + 1);
				t += 2ll << (i + 1);
			}
		}
	};
	rec(0);
	cout << "No\n";

	return 0;
}