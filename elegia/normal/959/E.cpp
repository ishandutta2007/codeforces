#include <cstdio>

using namespace std;

typedef long long ll;

ll dp[60];
ll n, ans, cur;

int main() {
	scanf("%lld", &n);
	dp[0] = 1;
	--n;
	for (int i = 1; i < 60; ++i)
		dp[i] = (dp[i - 1] << 1) + (1LL << (i - 1));
	for (int i = 0; i < 60; ++i)
		if ((n >> i) & 1)
			ans += dp[i];
	printf("%lld\n", ans);
	return 0;
}