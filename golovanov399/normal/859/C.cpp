#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	int dp[2] = {0, 0};
	int tmp[2] = {0, 0};
	for (int i = n - 1; i >= 0; --i) {
		tmp[0] = max(a[i] + dp[1], dp[0]);
		tmp[1] = min(a[i] + dp[1], dp[0]);
		dp[0] = tmp[0];
		dp[1] = tmp[1];
	}

	cout << dp[1] << " " << accumulate(all(a), 0) - dp[1] << "\n";

	return 0;
}