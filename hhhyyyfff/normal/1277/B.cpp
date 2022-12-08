#include <cstdio>
#include <algorithm>

using namespace std;

int t, n, m, ans, a[200010];

bool cmp(int x, int y) { return x > y; }

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
        	scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1, cmp);
		m = n;
		for (int i = 2; i <= n; ++i) {
			if (a[i - 1] == a[i]) {
				a[i - 1] = -1;
				--m;
			}
		}
		ans = 0;
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= m; ++i) {
			int s = 1;
			while (a[i] % 2 == 0) {
				int l = i + 1, r = m, mid;
				while (l < r) {
					mid = (l + r) / 2;
					if (a[mid] <= a[i]) {
						r = mid;
					} else {
						l = mid + 1;
					}
				}
				if (a[l] == a[i]) {
					s = 0;
				}
				ans += s;
				a[i] /= 2;
			}
		}
		printf("%d\n", ans);
    }
    return 0;
}