#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int L = 31;
using State = array<long long, L>;
const State def = []() { State res; res.fill(-1e18); return res; }();
void remax(long long& x, long long y) {
	x = (x > y) ? x : y;
}

void solve() {
	int n = nxt(), k = nxt();
	State dp = def;
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		auto nw = def;
		int cur = nxt();
		for (int j = 0; j < L; ++j) {
			// we use a normal key
			remax(nw[j], dp[j] - k + (cur >> j));
			// we use a faggot key
			remax(nw[min(L - 1, j + 1)], dp[j] + (cur >> (j + 1)));
		}
		dp.swap(nw);
	}
	cout << *max_element(all(dp)) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}