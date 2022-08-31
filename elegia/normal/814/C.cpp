#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 1510;

int n, m;
char s[N];
int f[26][N];
int dp[N][N];

int main() {
	scanf("%d%s", &n, s + 1);
	for (int i = 0; i < 26; ++i) {
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= n; ++j)
			if (s[j] == 'a' + i) {
				for (int k = 0; k <= n; ++k) {
					dp[j][k] = dp[j - 1][k] + 1;
					f[i][k] = max(f[i][k], dp[j][k]);
				}
			} else
				for (int k = 1; k <= n; ++k) {
					dp[j][k] = dp[j - 1][k - 1] + 1;
					f[i][k] = max(f[i][k], dp[j][k]);
				}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		printf("%d\n", f[c - 'a'][x]);
	}
	return 0;
}