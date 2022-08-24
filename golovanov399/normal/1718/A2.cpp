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
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> p(n + 1);
	for (int i = 0; i < n; ++i) {
		p[i + 1] = p[i] ^ a[i];
	}
	vector<int> dp(n + 1);
	map<int, int> last;
	last[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		if (auto it = last.find(p[i]); it != last.end()) {
			dp[i] = min(dp[i], dp[it->second] + i - it->second - 1);
		}
		last[p[i]] = i;
	}
	cout << dp[n] << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}