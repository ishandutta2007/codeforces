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
	sort(all(a));

	{
		long long s = 0;
		for (int i = 1; i < n; ++i) {
			s += a[0] + a[i];
		}
		if (s > 0) {
			cout << "INF\n";
			return;
		}
	}
	{
		long long s = 0;
		for (int i = 0; i < n - 1; ++i) {
			s += a[n - 1] + a[i];
		}
		if (s < 0) {
			cout << "INF\n";
			return;
		}
	}

	long long ans = LLONG_MIN;
	long long sl = 0, sr = accumulate(all(a), 0ll);
	for (int i = 0; i < n - 1; ++i) {
		sl += a[i];
		sr -= a[i];
		long long A = -1ll * a[0] * (n - 1 - i) - sr - 1ll * a.back() * (i + 1) - sl + a[0] + a.back();
		long long B = a[0] * sr + a.back() * sl - 1ll * a[0] * a.back();
		ans = max({ans, A * a[i] + B, A * a[i + 1] + B});
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