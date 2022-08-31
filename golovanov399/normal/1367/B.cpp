#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	int cnt[2][2];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		cnt[i % 2][a[i] % 2] += 1;
	}
	cout << (cnt[0][1] != cnt[1][0] ? -1 : cnt[0][1]) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}