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
	int n = nxt(), x = nxt();
	vector<long long> cnt(x + 1);
	for (int i = 0; i < n; ++i) {
		cnt[nxt()] += 1;
	}
	for (int i = 0; i < x; ++i) {
		if (cnt[i] % (i + 1)) {
			cout << "No\n";
			return;
		}
		cnt[i + 1] += cnt[i] / (i + 1);
	}
	cout << "Yes\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}