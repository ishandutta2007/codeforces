#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

void out(pair<int, int> p) {
	string s = to_string(p.second);
	while (s.length() < (size_t)p.first + 1) {
		s = '0' + s;
	}
	printf("%s\n", s.c_str());
}

int main() {
	int n = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = to_string(nxt());
	}

	vector<vector<pair<int, int>>> guys(n);
	vector<pair<int, int>> all_guys;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 9; ++j) {
			int x = 0;
			for (int k = j; k < 9; ++k) {
				x = x * 10 + a[i][k] - '0';
				guys[i].push_back({k - j, x});
			}
		}
		sort(all(guys[i]));
		guys[i].resize(unique(all(guys[i])) - guys[i].begin());
		for (auto x : guys[i]) {
			all_guys.push_back(x);
		}
	}

	sort(all(all_guys));
	all_guys.resize(unique(all(all_guys)) - all_guys.begin());
	vector<vector<int>> intguys(n);
	for (int i = 0; i < n; ++i) {
		for (auto x : guys[i]) {
			intguys[i].push_back(lower_bound(all(all_guys), x) - all_guys.begin());
		}
	}

	int sz = all_guys.size();
	vector<int> cnt(sz);
	for (int i = 0; i < n; ++i) {
		for (int x : intguys[i]) {
			cnt[x] += 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)intguys[i].size(); ++j) {
			if (cnt[intguys[i][j]] == 1) {
				out(all_guys[intguys[i][j]]);
				break;
			}
		}
	}

	return 0;
}