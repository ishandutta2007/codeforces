#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int main() {
	cin.sync_with_stdio(false);

	int n = nxt();
	vector<char> can(26, 1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		char act;
		string s;
		cin >> act >> s;
		vector<char> present(26, 0);
		for (char c : s) {
			present[c - 'a'] = 1;
		}
		int count = accumulate(all(can), 0);
		if (act == '.') {
			for (char c : s) {
				can[c - 'a'] = 0;
			}
		} else if (act == '!') {
			for (int j = 0; j < 26; ++j) {
				if (!present[j]) {
					can[j] = 0;
				}
			}
		} else {
			if (i == n - 1) {
				can = vector<char>(26, 0);
				can[s[0] - 'a'] = 1;
			} else {
				can[s[0] - 'a'] = 0;
			}
		}

		if (count == 1 && act != '.') {
			++ans;
		}
		if (i == n - 1 && act == '?' && count == 1) {
			--ans;
		}
	}

	printf("%d\n", ans);

	return 0;
}