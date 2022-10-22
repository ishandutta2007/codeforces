#include <bits/stdc++.h>
using namespace std;

int a[500010];
int L[500010], R[500010], LL[500010], RR[500010];
vector <int> all[500010];
int n;
multiset <int> S;

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) {
			all[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			L[i] = L[i - 1] + (a[i] == 0);
			LL[i] = 0, RR[i] = 0;
		}
		R[n + 1] = 0;
		for (int i = n; i >= 1; i--) {
			R[i] = R[i + 1] + (a[i] == 0);
		}
		int Z = L[n];
		for (int i = 1; i <= n; i++) {
			if (R[i] >= Z / 2) LL[a[i]] = max(LL[a[i]], L[i]);
			if (L[i] >= Z / 2) RR[a[i]] = max(RR[a[i]], R[i]);
		}
		for (int i = 1; i <= n; i++) {
			all[LL[i]].push_back(RR[i]);
		}
		int ans = 0;
		S.clear();
		for (int i = n; i >= 0; i--) {
			for (int j = 0; j < all[i].size(); j++) {
				S.insert(all[i][j]);
			}
			if (i == 0) break;
			if (S.size()) S.erase(S.begin()), ans++;
		}
		for (int i = n; i >= 1; i--) {
			if (!S.size()) break;
			int x = *(--S.end());
			if (x >= i) S.erase(--S.end()), ans++;
		}
		printf("%d\n", min(ans, Z >> 1));
	}
	return 0;
}