#include <cstdio>

#include <algorithm>
#include <numeric>

using namespace std;

const int N = 110;

int n, m, sumk;
int a[N];
int cnt[N], k[N];

bool pred(int x);

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &k[i]);
	sumk = accumulate(k + 1, k + m + 1, 0);
	for (int i = 1; i + sumk - 1 <= n; ++i)
		if (pred(i)) {
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}

bool pred(int x) {
	copy(k + 1, k + m + 1, cnt + 1);
	for (int i = 0; i < sumk; ++i)
		--cnt[a[i + x]];
	return all_of(cnt + 1, cnt + m + 1, [](int q) { return q == 0; });
}