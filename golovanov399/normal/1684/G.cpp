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

mt19937 rr;
mt19937_64 rr64;

inline std::uint_fast32_t custom_rand() {
	return rr();
}

inline std::uint_fast64_t custom_rand64() {
	return rr64();
}

template <typename RandomIt>
inline void custom_random_shuffle(RandomIt begin, RandomIt end) {
	shuffle(begin, end, rr);
}

#define rand custom_rand
#define rand64 custom_rand64
#define random_shuffle custom_random_shuffle

vector<int> kuhn_matching(const vector<vector<int>>& ed) {
	int m = 0;
	for (const auto& v : ed) {
		if (!v.empty()) {
			m = std::max(m, *max_element(all(v)) + 1);
		}
	}
	const int n = ed.size();

	vector<int> rt(m, -1);
	vector<int> lt(n, -1);
	vector<int> used(n);
	int timer = 0;

	vector<int> perm(n);
	iota(all(perm), 0);
	random_shuffle(all(perm));

	for (int i : perm) {
		for (int x : ed[i]) {
			if (rt[x] == -1) {
				rt[x] = i;
				lt[i] = x;
				break;
			}
		}
	}

	std::function<bool(int)> dfs = [&](int v) {
		if (used[v] == timer) {
			return false;
		}
		used[v] = timer;
		for (int x : ed[v]) {
			if (rt[x] == -1) {
				lt[v] = x;
				rt[x] = v;
				return true;
			}
		}
		for (int x : ed[v]) {
			if (dfs(rt[x])) {
				lt[v] = x;
				rt[x] = v;
				return true;
			}
		}
		return false;
	};

	for (int run = 1; run;) {
		run = 0;
		++timer;
		for (int i : perm) {
			if (lt[i] == -1 && dfs(i)) {
				run = 1;
			}
		}
	}

	return lt;
}

void solve() {
	int n = nxt(), m = nxt();
	bool ok = true;
	vector<int> big, small;
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		if (2 * x >= m) {
			ok = false;
		} else if (3 * x > m) {
			big.push_back(x);
		} else {
			small.push_back(x);
		}
	}
	if (!ok) {
		cout << "-1\n";
		return;
	}

	const int bs = big.size(), ss = small.size();
	vector<vector<int>> ed(bs);
	for (int i = 0; i < bs; ++i) {
		for (int j = 0; j < ss; ++j) {
			if (big[i] % small[j] == 0 && 2 * big[i] + small[j] <= m) {
				ed[i].push_back(j);
			}
		}
	}
	auto matching = kuhn_matching(ed);
	if (any_of(all(matching), [](int x) { return x == -1; })) {
		cout << "-1\n";
		return;
	}
	cout << ss << "\n";
	vector<char> used(ss);
	for (int i = 0; i < bs; ++i) {
		int j = matching[i];
		used[j] = true;
		cout << 2 * big[i] + small[j] << " " << big[i] + small[j] << "\n";
	}
	for (int i = 0; i < ss; ++i) {
		if (!used[i]) {
			cout << 3 * small[i] << " " << 2 * small[i] << "\n";
		}
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}