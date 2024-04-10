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

inline long long nxt() {
	long long x;
	scanf("%lld", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	map<int, vector<int>> M;
	for (int i = 0; i < n; ++i) {
		M[__builtin_ctzll(a[i])].push_back(i);
	}
	int mx = 0;
	for (const auto& [k, v] : M) {
		mx = max(mx, (int)v.size());
	}
	vector<int> used(n);
	for (const auto& [k, v] : M) {
		if ((int)v.size() == mx) {
			for (int x : v) {
				used[x] = 1;
			}
			break;
		}
	}
	cout << n - accumulate(all(used), 0) << "\n";
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			printf("%lld ", a[i]);
		}
	}
	printf("\n");

	return 0;
}