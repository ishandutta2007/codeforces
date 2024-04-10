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

long long f(int n, int k) {
	return n % k * 1ll * (n / k + 1) * (n / k + 1) + (k - n % k) * 1ll * (n / k) * (n / k);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt();
	int need = k - n;
	vector<int> a(n);
	generate(all(a), nxt);
	long long ans = 0;
	for (auto x : a) {
		ans += 1ll * x * x;
	}
	vector<int> d(n, 1);

	set<pair<long long, int>> S;
	for (int i = 0; i < n; ++i) {
		S.insert({f(a[i], 2) - f(a[i], 1), i});
	}
	while (need --> 0) {
		auto [delta, i] = *S.begin();
		S.erase(S.begin());
		ans += delta;
		d[i] += 1;
		S.insert({f(a[i], d[i] + 1) - f(a[i], d[i]), i});
	}
	cout << ans << "\n";

	return 0;
}