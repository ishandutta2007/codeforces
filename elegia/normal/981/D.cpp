#include <cstdio>
#include <cstring>

#include <algorithm>
#include <bitset>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 70;

int n, a;
bitset<N> dp[N];
ll sum[N];

int main() {
	scanf("%d%d", &n, &a);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &sum[i]);
	for (int i = 1; i <= n; ++i)
		sum[i] += sum[i - 1];
	ll ans = 0;
	dp[0].set(0);
	for (int l = 60; l >= 0; --l) {
		ll cur = ans ^ (1LL << l);
		for (int i = 1; i <= n; ++i) {
			dp[i].reset();
			for (int j = 0; j < i; ++j)
				if (((sum[i] - sum[j]) & cur) == cur)
					dp[i] |= dp[j] << 1;
		}
		if (dp[n][a])
			ans ^= 1LL << l;
	}
	printf("%lld\n", ans);
	return 0;
}