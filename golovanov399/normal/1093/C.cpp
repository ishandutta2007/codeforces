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

int main() {
	int n = nxt();
	vector<long long> b(n / 2);
	for (int i = 0; i < n / 2; ++i) {
		scanf("%lld", &b[i]);
	}

	vector<long long> a(n);
	a[n - 1] = b[0];
	for (int i = 1; i < n / 2; ++i) {
		a[i] = max(a[i - 1], b[i] - a[n - i]);
		a[n - 1 - i] = b[i] - a[i];
	}
	assert(is_sorted(all(a)));
	for (long long x : a) {
		printf("%lld ", x);
	}
	printf("\n");

	return 0;
}