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
	int n = nxt();
	vector<long long> a(n);
	for (auto& x : a) {
		scanf("%lld", &x);
	}
	for (int par : {0, 1}) {
		long long g = 0;
		for (int i = par; i < n; i += 2) {
			g = gcd(g, a[i]);
		}
		bool ok = true;
		for (int i = par ^ 1; i < n; i += 2) {
			ok &= !!(a[i] % g);
		}
		if (ok) {
			cout << g << "\n";
			return;
		}
	}
	cout << "0\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}