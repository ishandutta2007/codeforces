#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 500010;

int n, cnt;
ll ans;
int a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] < 0) {
			++cnt;
			ans += -a[i];
		} else
			ans += a[i];
	}
	if (n == 1) {
		printf("%d\n", a[1]);
		return 0;
	}
	if (cnt == 0) {
		ans -= 2 * *min_element(a + 1, a + n + 1);
	} else if (cnt == n)
		ans += 2 * *max_element(a + 1, a + n + 1);
	printf("%lld\n", ans);
	return 0;
}