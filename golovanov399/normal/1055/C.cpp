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

long long intersect(long long l1, long long len1, long long l2, long long len2) {
	long long r1 = l1 + len1;
	long long r2 = l2 + len2;
	return max<long long>(0, min(r1, r2) - max(l1, l2));
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	long long la, ra, ta;
	long long lb, rb, tb;
	cin >> la >> ra >> ta >> lb >> rb >> tb;

	long long g = gcd(ta, tb);
	long long len_a = ra - la + 1;
	long long len_b = rb - lb + 1;
	la %= g;
	lb %= g;

	long long ans = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			ans = max(ans, intersect(la + i * g, len_a, lb + j * g, len_b));
		}
	}

	cout << ans << "\n";

	return 0;
}