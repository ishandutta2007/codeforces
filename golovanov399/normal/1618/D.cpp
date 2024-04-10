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
	int n = nxt(), k = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	int ans = accumulate(a.begin(), a.begin() + n - 2 * k, 0);
	for (int i = 0; i < k; ++i) {
		ans += a[n - k + i] == a[n - 2 * k + i];
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}