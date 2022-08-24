#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

long long f(int n, int k) {
	return k + 1ll * n * (k - 1) / 2;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<long long> a;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i) {
			continue;
		}
		a.push_back(f(n, i));
		if (i * i < n) {
			a.push_back(f(n, n / i));
		}
	}
	sort(all(a));
	for (long long x : a) {
		printf("%lld ", x);
	}
	printf("\n");

	return 0;
}