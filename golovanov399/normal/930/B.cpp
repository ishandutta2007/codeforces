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
	scanf("%d", &x);
	return x;
}

const int N = 5555;
int cnt[N][26];

int main() {
	string s;
	cin >> s;
	int n = s.length();

	auto t = s + s;

	vector<vector<int>> poses(26);
	for (int i = 0; i < n; ++i) {
		poses[s[i] - 'a'].push_back(i);
	}

	int good_outcomes = 0;

	for (int c = 0; c < 26; ++c) {
		if (poses[c].empty()) {
			continue;
		}

		for (int i = 0; i < n; ++i) {
			memset(cnt[i], 0, sizeof(cnt[i]));
		}

		for (int p : poses[c]) {
			for (int i = 0; i < n; ++i) {
				cnt[i][t[p + i] - 'a'] += 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int cnt_ones = 0;
			for (int j = 0; j < 26; ++j) {
				if (cnt[i][j] == 1) {
					++cnt_ones;
				}
			}
			ans = max(ans, cnt_ones);
		}

		good_outcomes += ans;
	}

	cout << setprecision(10) << fixed;
	cout << 1.0 * good_outcomes / n << "\n";

	return 0;
}