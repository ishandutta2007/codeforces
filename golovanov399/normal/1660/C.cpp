#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	string s;
	cin >> s;
	const int n = s.length();
	vector<int> last(26, -1);
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		int d = s[i] - 'a';
		dp[i + 1] = dp[i];
		if (last[d] > -1) {
			dp[i + 1] = max(dp[i + 1], dp[last[d]] + 2);
		}
		last[d] = i;
	}
	cout << n - dp[n] << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}