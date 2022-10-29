#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((L + R + 1) >> 1)
using namespace std;
const int MAXN = 2000600;
const int mod = 998244353;
typedef long long LL;
typedef pair<int, int> PII;
int n, m, T, a[MAXN];
int main() {
#ifdef TEST
	freopen("input.txt", "r", stdin);
#endif
	int T;
	cin >> T;
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) a[i] = 0;
		for (int i = 0, u; i < n; ++i) {
			scanf("%d", &u);
			a[u - 1]++;
		}
		sort(a, a + n);
		int st = 0;
		while (!a[st]) st++;
		int ans = MAXN;
		for (int T = 1; T <= a[st] + 1; ++T) {
			int cnt = 0;
			for (int i = st; i < n; ++i) {
				int page = (a[i] + T - 1) / T;
				if (a[i] < (T - 1) * page) {
					goto label;
				}
				cnt += page;
			}
			// cout << T << " " << cnt << endl;
			ans = min(ans, cnt);
		label:
			continue;
		}
		printf("%d\n", ans);
	}
	return 0;
}