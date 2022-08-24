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

int main() {
	int n = nxt();
	string s;
	cin >> s;
	int init_cnt = 0;
	int mask = (1 << 26) - 1;
	for (char c : s) {
		if (c != '*') {
			++init_cnt;
			mask &= ~(1 << (c - 'a'));
		}
	}
	int init_mask = (~mask) & ((1 << 26) - 1);

	int m = nxt();
	while (m--) {
		string t;
		cin >> t;
		bool ok = true;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if ((1 << (t[i] - 'a')) & init_mask) {
				++cnt;
			}
			if (s[i] != '*' && s[i] != t[i]) {
				ok = false;
				break;
			}
		}
		if (!ok || cnt != init_cnt) {
			continue;
		}
		int msk = 0;
		for (char c : t) {
			msk |= 1 << (c - 'a');
		}
		mask &= msk;
	}
	cout << __builtin_popcount(mask) << "\n";

	return 0;
}