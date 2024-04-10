#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
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

const int N = 1010;

int n;
int l[N], r[N], a[N];
int cnt[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &l[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &r[i]);
	for (int i = 1; i <= n; ++i) {
		if (l[i] + r[i] >= n) {
			puts("NO");
			return 0;
		}
		cnt[l[i] + r[i]] = 1;
	}
	for (int i = n - 1; i >= 0; --i)
		cnt[i] += cnt[i + 1];
	for (int i = 1; i <= n; ++i)
		a[i] = cnt[l[i] + r[i]];
	for (int i = 1; i <= n; ++i) {
		int cl = 0, cr = 0;
		for (int j = 1; j < i; ++j)
			cl += a[j] > a[i];
		for (int j = i + 1; j <= n; ++j)
			cr += a[j] > a[i];
		if (cl != l[i] || cr != r[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}