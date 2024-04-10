#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 300010;

int n;
ll ans = 0;
int a[N], mex[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		mex[i] = max(mex[i - 1], a[i]);
	int m = mex[n];
	for (int i = n; i; --i) {
		ans += m - a[i];
		if (m > mex[i - 1])
			--m;
	}
	printf("%lld\n", ans);
	return 0;
}