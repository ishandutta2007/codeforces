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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(all(a));

	vector<long long> d;
	for (int i = 0; i < n - 1; ++i) {
		d.push_back(a[i + 1] - a[i]);
	}
	sort(all(d));
	vector<long long> p(n);
	p[0] = 0;
	for (int i = 0; i < (int)d.size(); ++i) {
		p[i + 1] = p[i] + (n - i) * (d[i] - (i ? d[i - 1] : 0ll));
	}

	int q = nxt();
	while (q--) {
		long long l, r;
		scanf("%lld%lld", &l, &r);
		r -= l;
		r += 1;
		int idx = lower_bound(all(d), r) - d.begin();
		printf("%lld ", p[idx] + (n - idx) * (r - (idx ? d[idx - 1] : 0ll)));
	}
	printf("\n");

	return 0;
}