#include <cstdio>

#include <algorithm>

using namespace std;

const int N = 200010;

int n;
int l[N], r[N];

int disc[N * 4], cnt[N * 4];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		disc[(i - 1) * 4] = l[i];
		disc[(i - 1) * 4 + 1] = l[i] + 1;
		disc[(i - 1) * 4 + 2] = r[i];
		disc[(i - 1) * 4 + 3] = r[i] + 1;
	}
	sort(disc, disc + n * 4);
	for (int i = 1; i <= n; ++i) {
		++cnt[l[i] = lower_bound(disc, disc + n * 4, l[i]) - disc];
		--cnt[upper_bound(disc, disc + n * 4, r[i]) - disc];
		r[i] = lower_bound(disc, disc + n * 4, r[i]) - disc;
	}
	for (int i = 1; i < n * 4; ++i)
		cnt[i] += cnt[i - 1];
	cnt[0] = cnt[0] >= 2;
	for (int i = 1; i < n * 4; ++i)
		cnt[i] = (cnt[i] >= 2) + cnt[i - 1];
	for (int i = 1; i <= n; ++i) {
		int sum = cnt[r[i]] - (l[i] ? cnt[l[i] - 1] : 0);
		if (sum == r[i] - l[i] + 1) {
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}