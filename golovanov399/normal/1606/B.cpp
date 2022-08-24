#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	long long n, k;
	cin >> n >> k;
	long long cur = 1;
	long long ans = 0;
	while (cur < n && cur <= k) {
		cur = min(n, 2 * cur);
		++ans;
	}
	ans += (n - cur + k - 1) / k;
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}