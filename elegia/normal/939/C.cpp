#include <cstdio>
#include <cstring>

#include <algorithm>
#include <limits>

using namespace std;

typedef long long ll;

const int N = 100010;

int n, s, f;
int a[N], cnt[N * 3];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	scanf("%d%d", &s, &f);
	for (int i = 1; i <= n; ++i) {
		cnt[max(1, s - i + 1)] += a[i];
		cnt[max(1, min(n, f - i + 1))] -= a[i];
		cnt[s - i + n + 1] += a[i];
		cnt[f - i + n + 1] -= a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cnt[i] += cnt[i - 1];
	}
	printf("%ld\n", max_element(cnt + 1, cnt + n + 1) - cnt);
	return 0;
}