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
	int n = nxt(), k = nxt();
	vector<int> a(n);
	long long s = 0;
	for (int i = 0; i < n; ++i) {
		s += a[i] = nxt();
		a[i] += i;
	}
	for (int i = 1; i <= k; ++i) {
		s += n - i;
	}
	sort(all(a));
	reverse(all(a));
	for (int i = 0; i < k; ++i) {
		s -= a[i];
	}
	cout << s << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}