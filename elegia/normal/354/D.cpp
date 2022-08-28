#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>
#include <limits>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 100010, B = 800;

int n, k, b;
int dp[B], tmp[B];
int cnt[B];
vector<int> pts[N];

int sz(int n) { return n * (n + 1) / 2; }

int main() {
	int ext = 0;
	scanf("%d%d", &n, &k);
	b = min(n, (int)ceil(sqrt(k * 6)));
	while (k--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (n - x + 1 > b)
			++ext;
		else
			pts[n - x + y].push_back(n - x + 1);
	}
	for (int i = 1; i <= n; ++i) {
		memcpy(tmp, dp, sizeof(tmp));
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < pts[i].size(); ++j)
			++cnt[pts[i][j]];
		for (int j = b; j >= 0; --j)
			cnt[j] += cnt[j + 1];
		int cmin = numeric_limits<int>::max();
		for (int j = b; j; --j) {
			dp[j] = min(tmp[j - 1] + cnt[j + 1] * 3, cmin);
			cmin = min(cmin, tmp[j - 1] + 3 * cnt[j + 1] + 2 + sz(j));
		}
		dp[0] = min(tmp[0] + 3 * cnt[1], cmin);
	}
	printf("%d\n", dp[0] + ext * 3);
	return 0;
}