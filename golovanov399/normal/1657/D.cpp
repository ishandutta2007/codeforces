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

void remax(long long& x, long long y) {
	x = (x > y) ? x : y;
}

void solve() {
	int n = nxt(), C = nxt();
	vector<long long> mx(C + 1, 0);
	for (int i = 0; i < n; ++i) {
		int c = nxt(), d = nxt(), h = nxt();
		remax(mx[c], 1ll * d * h);
	}
	for (int i = 1; i <= C; ++i) {
		for (int j = 1; i * j <= C; ++j) {
			remax(mx[i * j], mx[i] * j);
		}
	}
	map<long long, int> M;
	long long last = 0;
	for (int i = 1; i <= C; ++i) {
		if (mx[i] > last) {
			M[last = mx[i]] = i;
		}
	}

	int m = nxt();
	while (m--) {
		int d = nxt();
		long long h;
		scanf("%lld", &h);
		long long x = d * h;
		auto it = M.upper_bound(x);
		if (it == M.end()) {
			cout << "-1 ";
		} else {
			cout << it->second << " ";
		}
	}
	cout << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}