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
	int n;
	long long k;
	cin >> n >> k;
	if (n < 61 && k > (1ll << (n - 1))) {
		cout << "-1\n";
		return;
	}
	vector<char> used(n);
	k -= 1;
	while (k) {
		used[n - 1 - __builtin_ctzll(k)] = true;
		k &= k - 1;
	}
	vector<int> bars;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			bars.push_back(i);
		}
	}
	bars.push_back(n);
	for (int i = 0, j = 1; i < (int)bars.size(); ++i) {
		for (int k = bars[i]; k >= j; --k) {
			cout << k << " ";
		}
		j = bars[i] + 1;
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}