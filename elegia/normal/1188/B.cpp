#include <cstdio>
#include <cstring>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 300010;

int n, k, p;
int a[N], b[N];

int main() {
	//freopen("b.in", "r", stdin);
	scanf("%d%d%d", &n, &p, &k);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		a[i] = x;
		b[i] = (p + x * (ll)x % p * x % p - k) * x % p;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	ll ans = 0;
	int lst = a[1], l = 1;
	a[n + 1] = -1;
	for (int i = 1; i <= n + 1; ++i) {
		if (a[i] != lst) {
			int cnt = i - l;
			if (lst * (ll)lst % p * lst % p * 4 % p != k)
				ans -= cnt * (cnt - 1LL) / 2;
			lst = a[i];
			l = i;
		}
	}
	lst = b[1]; l = 1;
	b[n + 1] = -1;
	for (int i = 1; i <= n + 1; ++i) {
		if (b[i] != lst) {
			int cnt = i - l;
			ans += cnt * (cnt - 1LL) / 2;
			lst = b[i];
			l = i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}