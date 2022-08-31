#include <cstdio>

#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const int N = 1000010;

int n, m, k;
int a[N];
int pre[N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	iota(pre, pre + n + 1, 0);
	while (m--) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			puts("-1");
			return 0;
		}
		pre[x] = x - 1;
	}
	for (int i = 1; i <= k; ++i)
		scanf("%d", &a[i]);
	int dist = 1;
	for (int i = 0; i < n; ++i) {
		pre[i] = pre[pre[i]];
		dist = max(dist, i - pre[i] + 1);
	}
	if (dist > k) {
		puts("-1");
		return 0;
	}
	ll ans = numeric_limits<ll>::max();
	for (int i = dist; i <= k; ++i) {
		int cnt = 0;
		int pos = 0;
		while (pos < n) {
			++cnt;
			pos += i;
			if (pos < n)
				pos = pre[pos];
		}
		ans = min(ans, cnt * (ll)a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}