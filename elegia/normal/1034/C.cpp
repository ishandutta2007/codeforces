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

const int N = 1000010, P = 1000000007;

int n;
int p[N], cnt[N];
ll a[N];

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
#ifdef LBT
//	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for (int i = 2; i <= n; ++i)
		scanf("%d", &p[i]);
	for (int i = n; i; --i)
		a[p[i]] += a[i];
	for (int i = 1; i <= n; ++i) {
		ll g = a[1] / gcd(a[1], a[i]);
		if (g <= n)
			++cnt[g];
	}
	for (int i = n; i; --i)
		for (int j = i * 2; j <= n; j += i)
			cnt[j] += cnt[i];
	for (int i = n; i; --i) {
		if (cnt[i] != i) {
			cnt[i] = 0;
			continue;
		}
		cnt[i] = 1;
		for (int j = i * 2; j <= n; j += i)
			if ((cnt[i] += cnt[j]) >= P)
				cnt[i] -= P;
	}
	printf("%d\n", cnt[1]);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}