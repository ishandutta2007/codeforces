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

struct Seg {
	int l, r;
};

void solve(int l, int r) {
	const int n = 22;
	vector<vector<pair<int, int>>> a(n);
	vector<Seg> seg(n);
	seg[0] = {0, 0};
	for (int i = 1; i < n - 1; ++i) {
		seg[i] = {1, 0};
		for (int j = 0; j < i; ++j) {
			assert(seg[j].l <= seg[i].r);
			a[j].push_back({i, seg[i].r + 1 - seg[j].l});
			seg[i].r += seg[j].r - seg[j].l + 1;
		}
	}
	a[0].push_back({n - 1, l});
	seg[n - 1] = {l + 1, l};
	int len = r - l;
	for (int j = 1; j < n - 1; ++j) {
		if (len & (1 << (j - 1))) {
			assert(seg[n - 1].r >= seg[j].l);
			a[j].push_back({n - 1, seg[n - 1].r + 1 - seg[j].l});
			seg[n - 1].r += seg[j].r - seg[j].l + 1;
		}
	}
	assert(seg[n - 1].r == r);

	int m = 0;
	for (auto v : a) {
		m += v.size();
	}
	cout << "YES\n" << n << " " << m << "\n";
	for (int i = 0; i < n; ++i) {
		for (auto [j, w] : a[i]) {
			cout << i + 1 << " " << j + 1 << " " << w << "\n";
		}
	}
}

int main() {
	int l = nxt(), r = nxt();
	solve(l, r);
	// for (int n = 1; n <= 1000000; ++n) {
	// 	solve(1, n);
	// }

	return 0;
}