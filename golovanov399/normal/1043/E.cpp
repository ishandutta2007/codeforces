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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<array<int, 3>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i][0] = nxt();
		a[i][1] = nxt();
		a[i][0] -= a[i][1];
		a[i][2] = i;
	}

	sort(all(a));
	vector<long long> ans(n);
	long long sum_all = 0;
	for (auto p : a) {
		sum_all += p[1];
	}
	long long cur_fst = 0;
	for (int i = 0; i < n; ++i) {
		ans[a[i][2]] = sum_all + 1ll * a[i][1] * (n - 2);
		ans[a[i][2]] += cur_fst + 1ll * a[i][0] * (n - 1 - i);
		cur_fst += a[i][0];
	}

	// for (auto x : ans) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";

	sort(all(a), [](const array<int, 3>& p, const array<int, 3>& q) {
		return p[2] < q[2];
	});

	// for (auto v : a) {
	// 	cerr << "(" << v[0] << ", " << v[1] << ", " << v[2] << ") ";
	// }
	// cerr << "\n";

	while (m--) {
		int u = nxt() - 1, v = nxt() - 1;
		long long x = a[u][1];
		x += a[v][1];
		x += min(a[u][0], a[v][0]);
		ans[u] -= x;
		ans[v] -= x;
	}

	for (auto x : ans) {
		printf("%lld ", x);
	}
	printf("\n");

	return 0;
}