#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

const int N = 100010;

int n, m, w;
int a[N];
int pre[N * 2];

bool pred(int x);

int main() {
	scanf("%d%d%d", &n, &m, &w);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int l = *min_element(a + 1, a + n + 1), r = l + m;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (pred(mid))
			l = mid;
		else
			r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}

bool pred(int x) {
	int need = 0;
	memset(pre, 0, sizeof(pre));
	for (int i = 1; i <= n; ++i) {
		pre[i] += pre[i - 1];
		int ad = x - pre[i] - a[i];
		if (ad > 0) {
			need += ad;
			pre[i] += ad;
			pre[i + w] -= ad;
		}
		if (need > m)
			return false;
	}
	return true;
}