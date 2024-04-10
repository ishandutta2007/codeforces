#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void prefixFunction(const vector<int>& s, vector<int>& p) {
	if (s.size() == 0) {
		return;
	}
	p[0] = 0;
	for (size_t i = 1; i < s.size(); ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		p[i] = j;
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int x = nxt() - 1, y = nxt() - 1;
		if (x > y) {
			swap(x, y);
		}
		a[x].push_back(y - x);
		a[y].push_back(x - y + n);
	}
	vector<vector<int>> everything;
	for (auto& v : a) {
		sort(all(v));
		everything.push_back(v);
	}
	make_unique(everything);

	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		h[i] = lower_bound(all(everything), a[i]) - everything.begin();
	}

	vector<int> p(n);
	prefixFunction(h, p);
	puts(p[n - 1] * 2 >= n ? "Yes" : "No");

	return 0;
}