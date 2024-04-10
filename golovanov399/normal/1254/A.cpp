#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int r = nxt(), c = nxt();
	int k = nxt();
	vector<string> a(r);
	for (int i = 0; i < r; ++i) {
		cin >> a[i];
	}
	int cnt = 0;
	for (auto s : a) {
		for (char c : s) {
			if (c == 'R') {
				++cnt;
			}
		}
	}

	string alphabet = "";
	for (int i = 0; i < 26; ++i) {
		alphabet += (char)('a' + i);
	}
	for (int i = 0; i < 26; ++i) {
		alphabet += (char)('A' + i);
	}
	alphabet += "1234567890";
	vector<int> by_chicken(k, cnt / k);
	for (int i = 0; i < cnt % k; ++i) {
		++by_chicken[i];
	}
	int idx = 0;
	int cur = 0;
	vector<string> ans(r, string(c, '0'));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			int actual = j;
			if (i % 2) {
				actual = c - 1 - actual;
			}
			cur += (a[i][actual] == 'R');
			if (idx < k && cur > by_chicken[idx]) {
				++idx;
				cur = 1;
			}
			ans[i][actual] = alphabet[idx];
		}
	}

	for (auto s : ans) {
		cout << s << "\n";
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}