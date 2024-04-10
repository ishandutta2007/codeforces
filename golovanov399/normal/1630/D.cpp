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

const long long inf = 1e18;

template <typename T>
void remax(T& x, const T& y) {
	x = (x < y) ? y : x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<int> ar(n);
	generate(all(ar), nxt);
	int g = 0;
	for (int i = 0; i < m; ++i) {
		g = gcd(g, nxt());
	}
	vector<vector<int>> a(g);
	for (int i = 0; i < n; ++i) {
		a[i % g].push_back(ar[i]);
	}
	long long pars[2] = {0, 0};
	for (auto& v : a) {
		sort(all(v));
		long long s = accumulate(all(v), 0ll);
		long long cur[2] = {s, -inf};
		for (int i = 0; i < (int)v.size(); ++i) {
			s -= 2 * v[i];
			remax(cur[(i + 1) % 2], s);
		}
		pars[0] += cur[0];
		pars[1] += cur[1];
	}
	cout << max(pars[0], pars[1]) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}