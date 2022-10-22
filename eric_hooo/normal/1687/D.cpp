#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, int> pli;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2000000;

int a[1000010];
pli all[13000010];
int tp;

void Calc(long long l, long long r) {
	if (l > r) return ;
	int k = min((long long)N, r - l + 1);
	for (int i = 1; i <= k; i++) {
		long long L = 1ll * i * (i + 1) + 1, R = 1ll * (i + 1) * (i + 1) - 1;
		// [L, R] \in [l + x, r + x]
		// L >= l + x, R <= r + x
		// x <= L - l, x >= R - r
		long long lb = R - r, rb = L - l;
		all[tp++] = pli(lb, 1), all[tp++] = pli(rb + 1, -1);
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	Calc(-INF, a[0] - 1);
	for (int i = 0; i + 1 < n; i++) {
		Calc(a[i] + 1, a[i + 1] - 1);
	}
	Calc(a[n - 1] + 1, INF);
	sort(all, all + tp);
	int sum = 0;
	for (int i = 0; i < tp; i++) {
		sum += all[i].se;
		if (sum == N && i + 1 < tp && all[i + 1].fi > 0) {
			printf("%lld\n", max(0ll, all[i].fi));
			// auto Check = [&](long long x) -> bool {
			// 	long long l = sqrt(x) - 10;
			// 	while (l * l <= x) l++; l--;
			// 	return x - l * l < (l + 1) * (l + 1) - x;
			// };
			// for (int i = 0; i < n; i++) {
			// 	assert(Check(a[i] + it.fi));
			// }
			return 0;
		}
	}
	assert(0);
	return 0;
}