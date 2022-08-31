#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const int N = 200010;

int n, L;
ll a[N], b[N * 3], cnt[N * 6];

bool pred(int x);

int main() {
	scanf("%d%d", &n, &L);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++i)
		a[i] += L;
	for (int i = 1; i <= n * 2; ++i)
		b[n + i] = b[i] + L;
	b[n * 3 + 1] = L * 10LL;
	int l = 0, r = L / 2;
	while (l < r) {
		int mid = (l + r) / 2;
		if (pred(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}

bool pred(int x) {
	memset(cnt, 0, sizeof(cnt));
	int lP = 1, rP = 1;
	for (int i = 1; i <= n; ++i) {
		while (b[lP] + x < a[i])
			++lP;
		while (b[rP] - x <= a[i])
			++rP;
		++cnt[lP - i + n];
		--cnt[rP - i + n];
	}
	for (int i = 1; i <= n * 6; ++i) {
		cnt[i] += cnt[i - 1];
		if (cnt[i] >= n)
			return true;
	}
	return false;
}