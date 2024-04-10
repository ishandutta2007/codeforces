#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, long long> pil;

int n;
int a[510];
vector <pil> all, nxt;
vector <pil> cur;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		int x = a[i];
		cur.clear();
		for (int l = 1; l <= x; ) {
			int v = x / l, r = x / v;
			cur.push_back(mp(v, l));
			if (x % r == 0) cur.push_back(mp(v - 1, r));
			l = r + 1;
		}
		reverse(cur.begin(), cur.end());
		if (i == 0) all = cur, sort(all.begin(), all.end());
		else {
			int j = 0;
			nxt.clear();
			for (int i = 0; i < all.size(); i++) {
				while (j < cur.size() && cur[j].fi < all[i].fi) j++;
				long long minj = 0x3f3f3f3f3f3f3f3f;
				while (j < cur.size() && cur[j].fi == all[i].fi) minj = min(minj, cur[j].se), j++;
				if (minj != 0x3f3f3f3f3f3f3f3f) nxt.push_back(mp(all[i].fi, all[i].se + minj));
			}
			all = nxt;
		}
	}
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (auto it : all) {
		ans = min(ans, it.se);
	}
	printf("%lld\n", ans);
	return 0;
}