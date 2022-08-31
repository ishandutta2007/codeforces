#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using ld = long double;

void solve() {
	int n = nxt(), L = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	a.push_back(L);
	for (int i = n; i > 0; --i) {
		a[i] -= a[i - 1];
	}
	n += 1;

	vector<long double> pl(n + 1);
	vector<long double> pr(n + 1);
	for (int i = 0; i < n; ++i) {
		pl[i + 1] = pl[i] + (long double)a[i] / (i + 1);
	}
	for (int i = 0; i < n; ++i) {
		pr[n - i - 1] = pr[n - i] + (long double)a[n - 1 - i] / (i + 1);
	}
	int l = 0, r = n;
	while (r > l + 1) {
		int m = (l + r) / 2;
		if (pl[m] > pr[m]) {
			r = m;
		} else {
			l = m;
		}
	}
	ld d_rem = a[l];
	ld t_l = pl[l], t_r = pr[r];
	if (t_l < t_r) {
		d_rem -= (l + 1) * (t_r - t_l);
	} else {
		d_rem -= (n - r + 1) * (t_l - t_r);
	}
	ld t = max(t_l, t_r);
	cout << t + d_rem / (l + 1 + n - r + 1) << "\n";
}

int main() {
	cout << setprecision(10) << fixed;
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}