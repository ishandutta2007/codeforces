#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 200010;

int n, m;
ll sum[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &sum[i]);
		sum[i] += sum[i - 1];
	}
	ll dsum = 0;
	while (m--) {
		ll d;
		scanf("%lld", &d);
		dsum += d;
		int lst = upper_bound(sum + 1, sum + n + 1, dsum) - sum;
		if (lst == n + 1) {
			lst = 1;
			dsum = 0;
		}
		printf("%d\n", n - lst + 1);
	}
	return 0;
}