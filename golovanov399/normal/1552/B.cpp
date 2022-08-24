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

void solve() {
	int n = nxt();
	vector<array<int, 5>> a(n);
	for (int i = 0; i < n; ++i) {
		generate(all(a[i]), nxt);
	}

	auto is_better = [&](int i, int j) {
		int cnt = 0;
		for (int k = 0; k < 5; ++k) {
			cnt += a[i][k] < a[j][k];
		}
		return cnt >= 3;
	};

	int cand = 0;
	for (int i = 1; i < n; ++i) {
		if (is_better(i, cand)) {
			cand = i;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i != cand && is_better(i, cand)) {
			cout << "-1\n";
			return;
		}
	}
	cout << cand + 1 << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}