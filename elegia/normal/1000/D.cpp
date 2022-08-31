#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010, P = 998244353;

int n;
int dp[N], tmp[N];

int main() {
	scanf("%d", &n);
	dp[0] = 1;
	for (int rep = 0; rep < n; ++rep) {
		int a;
		scanf("%d", &a);
		memcpy(tmp, dp, sizeof(tmp));
		if (a > 0 && a <= n) {
			tmp[a] += dp[0];
			if (tmp[a] >= P)
				tmp[a] -= P;
		}
		for (int i = 0; i <= n; ++i) {
			tmp[i] += dp[i + 1];
			if (tmp[i] >= P)
				tmp[i] -= P;
		}
		memcpy(dp, tmp, sizeof(dp));
	}
	printf("%d\n", dp[0] ? dp[0] - 1 : P - 1);
	return 0;
}