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
	vector<int> our(n), guy(n);
	generate(all(our), nxt);
	generate(all(guy), nxt);
	sort(all(our));
	sort(all(guy));
	reverse(all(guy));
	vector<int> pour(n + 1), pguy(n + 1);
	partial_sum(all(our), pour.begin() + 1);
	partial_sum(all(guy), pguy.begin() + 1);

	auto check = [&](int cnt) {
		int k = n + cnt;
		int taken = k - k / 4;
		int our_old = max(0, taken - cnt);
		int guy_old = min(n, taken);
		return pour[n] - pour[n - our_old] + 100ll * (taken - our_old) >= pguy[guy_old];
	};

	int l = -1, r = 1e6;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		(check(mid) ? r : l) = mid;
	}
	cout << r << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}