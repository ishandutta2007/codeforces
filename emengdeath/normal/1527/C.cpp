#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <assert.h>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
int T, n;
int a[1000001];
int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		map<int, long long> f;
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			ans += 1ll * f[a[i]] * (n - i + 1);
			f[a[i]] += i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}