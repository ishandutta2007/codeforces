#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii a[200010];
int n;

bool Check(int mid) {
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur <= a[i].fi && mid - cur - 1 <= a[i].se) cur++;
		if (cur == mid) return 1;
	}
	return 0;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].fi, &a[i].se);
			swap(a[i].fi, a[i].se);
		}
		int l = 0, r = n;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (Check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}