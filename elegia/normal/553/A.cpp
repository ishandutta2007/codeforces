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

const int N = 1010, P = 1000000007;

int k, n;
int c[N];
int inv[N], fac[N], ifac[N];

int binom(int n, int m) {
	return fac[n] * (ll)ifac[m] % P * ifac[n - m] % P;
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif
	
	scanf("%d", &k);
	for (int i = 1; i <= k; ++i)
		scanf("%d", &c[i]);
	n = accumulate(c + 1, c + k + 1, 0);
	inv[1] = 1;
	for (int x = 2; x <= n; ++x)
		inv[x] = -(P / x) * (ll)inv[P % x] % P + P;
	fac[0] = ifac[0] = 1;
	for (int x = 1; x <= n; ++x) {
		fac[x] = fac[x - 1] * (ll)x % P;
		ifac[x] = ifac[x - 1] * (ll)inv[x] % P;
	}
	int ps = 0, ans = 1;
	for (int i = 1; i <= k; ++i) {
		ps += c[i];
		ans = ans * (ll)binom(ps - 1, c[i] - 1) % P;
	}
	printf("%d\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}