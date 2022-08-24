#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), x = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> p(n + 1);
	partial_sum(all(a), p.begin() + 1);
	for (int& y : p) {
		y %= x;
	}
	int fst = 0;
	while (fst <= n && !p[fst]) {
		++fst;
	}
	if (fst > n) {
		cout << "-1\n";
	} else {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans = max(ans, p[i] ? i : (i - fst));
		}
		cout << ans << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}