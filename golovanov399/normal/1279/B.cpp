#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), s = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	long long t = accumulate(all(a), 0ll);
	if (t <= s) {
		puts("0");
		return;
	}
	vector<long long> p(n + 1);
	for (int i = 0; i < n; ++i) {
		p[i + 1] = p[i] + a[i];
	}
	pair<int, int> cur = {upper_bound(all(p), s) - p.begin() - 1, 0};
	for (int i = 0; i < n; ++i) {
		if (p[i] >= s) {
			break;
		}
		cur = max(cur, {upper_bound(all(p), s + a[i]) - p.begin() - 2, i + 1});
	}
	cout << cur.second << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}