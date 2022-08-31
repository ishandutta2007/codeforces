#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <random>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int P = 1000000007, I2 = 500000004;
const int N = 1000010;

int n, k;
int a[N];
int stk[N], l[N], r[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int top = 0;
	for (int i = 1; i <= n; ++i) {
		while (top && a[stk[top]] < a[i])
			r[stk[top--]] = i - 1;
		stk[++top] = i;
		l[i] = stk[top - 1] + 1;
	}
	while (top)
		r[stk[top--]] = n;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int a = i - l[i], b = r[i] - i;
		if (a > b)
			swap(a, b);
		int d = a / (k - 1);
		int cnt = d * (ll)(2 + (d + 1) * (ll)(k - 1) % P) % P * I2 % P;
		a -= d * (k - 1);
		b -= d * (k - 1);
		int len = (k - 1) * d + 1;
		len = min(a + len, a + b + len - k + 1);
		if (len > 0) {
			b = max(0, b - k + 1);
			cnt = (cnt + len) % P;
			d = b / (k - 1);
			cnt = (cnt + d * (ll)len) % P;
			b -= d * (k - 1);
			len -= k - 1 - b;
			if (len > 0) {
				d = (len - 1) / (k - 1) + 1;
				cnt = (cnt + d * (ll)(len * 2LL - (d - 1) * (k - 1)) % P * I2 % P) % P;
			}
		}
		
		LOG("%d: %d\n", i, cnt);
		ans = (ans + cnt * (ll)::a[i]) % P;
	}
	printf("%d\n", ans);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}