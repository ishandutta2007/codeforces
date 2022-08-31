#include <cstdio>
#include <cstring>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

const int N = 1010, P = 998244353;

int n, k;
int a[N], dp[N][N];
int pre[N];

int norm(int x) { return x >= P ? (x - P) : x; }

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int lim = a[n] - a[1];
	int ans = 0;
	for (int i = 1; i <= lim; ++i) {
		if ((k - 1) * i > lim) break;
		int ptr = 0;
		memset(pre, 0, sizeof(pre));
		pre[0] = 1;
		for (int j = 1; j <= n; ++j) {
			while (a[ptr + 1] + i <= a[j]) {
				++ptr;
				for (int l = 1; l <= k; ++l)
					pre[l] = norm(pre[l] + dp[ptr][l]);
			}
			for (int l = 1; l <= k; ++l)
				dp[j][l] = pre[l - 1];
			ans = norm(ans + dp[j][k]);
		}
	}
	printf("%d\n", ans);
	return 0;
}