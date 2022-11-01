#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 200005, MOD = 1e9 + 7;
LL f[MAXN];
int T, n, b[MAXN];
map<LL, int> mp;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		LL ans = 1, sum = 0;
		f[0] = 1;
		mp.clear();
		mp[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", b + i);
			int k = i;
//			for (LL j = b[i]; k >= 0;) {
//				j -= b[k], --k;
//				if (j == b[k]) break;
//			}
			k = mp.find(sum) == mp.end() ? -1 : mp[sum];
			mp[sum] = i;
			sum += b[i];
			f[i] = ans;
			ans = (ans * 2 + MOD - (k >= 0 ? f[k] : 0)) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}