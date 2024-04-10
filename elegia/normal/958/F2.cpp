#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 200010;

int n, m, sumk, cnt;
int a[N], k[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &k[i]);
		cnt += k[i] != 0;
	}
	sumk = accumulate(k + 1, k + m + 1, 0);
	int l = 1, r = 0;
	while (cnt) {
		if (--k[a[++r]] == 0)
			--cnt;
		if (r > n) {
			puts("-1");
			return 0;
		}
	}
	int ans = r - l + 1 - sumk;
	for (; r <= n; --k[a[++r]]) {
		while (k[a[l]] < 0)
			++k[a[l++]];
		ans = min(ans, r - l + 1 - sumk);
	}
	printf("%d\n", ans);
	return 0;
}