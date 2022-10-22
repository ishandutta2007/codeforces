#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii a[200010];
priority_queue <int, vector <int>, greater <int> > q;

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].fi, &a[i].se);
		}
		sort(a, a + n);
		long long ans = 0;
		while (!q.empty()) q.pop();
		for (int i = n - 1; i >= 0; i--) {
			int j = i;
			while (j >= 0 && a[i].fi == a[j].fi) q.push(a[j].se), j--;
			while (n - q.size() < a[i].fi) ans += q.top(), q.pop();
			i = j + 1;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}