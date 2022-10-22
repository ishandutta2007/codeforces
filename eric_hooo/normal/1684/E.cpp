#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		static map <int, int> all; all.clear();
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			all[x]++;
		}
		static vector <pii> a; a = vector <pii>(all.begin(), all.end());
		static int need[100010];
		need[0] = 0;
		for (int i = 0; i < n; i++) {
			need[i + 1] = need[i] + (all.count(i) == 0);
		}
		static multiset <int> A, B; A.clear(), B.clear();
		int SA = 0, SB = 0;
		auto Insert = [&](int x) -> void {
			A.insert(x), SA += x;
			while (SA > k) {
				int tmp = *--A.end(); A.erase(--A.end()), B.insert(tmp);
				SA -= tmp, SB += tmp;
			}
		};
		int p = a.size(), ans = 0x3f3f3f3f;
		for (int i = n; i >= 0; i--) {
			if (all.count(i)) continue;
			while (p > 0 && a[p - 1].fi >= i) {
				p--, Insert(a[p].se);
			}
			if (need[i] <= k) {
				ans = min(ans, (int)B.size());
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}