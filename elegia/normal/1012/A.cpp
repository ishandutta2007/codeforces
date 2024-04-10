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
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010;

int n;
int a[N * 2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n * 2; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n * 2 + 1);
	ll ans = (a[n] - a[1]) * (ll)(a[n * 2] - a[n + 1]);
	for (int i = 2; i <= n; ++i)
		ans = min(ans, (a[i + n - 1] - a[i]) * (ll)(a[n * 2] - a[1]));
	printf("%lld\n", ans);
	return 0;
}