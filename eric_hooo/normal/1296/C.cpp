#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppp;

char s[200010];
pii a[200010];
vector <ppp> all;

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		scanf("%s", s + 1);
		a[0] = mp(0, 0);
		all.clear(), all.push_back(mp(a[0], 0));
		for (int i = 1; i <= n; i++) {
			a[i] = a[i - 1];
			if (s[i] == 'L') a[i].fi--;
			else if (s[i] == 'R') a[i].fi++;
			else if (s[i] == 'U') a[i].se++;
			else a[i].se--;
			all.push_back(mp(a[i], i));
		}
		sort(all.begin(), all.end());
		int l = -1, r = -1;
		for (int i = 1; i < all.size(); i++) {
			if (all[i].fi != all[i - 1].fi) continue;
			if (l == -1 || r - l + 1 > all[i].se - all[i - 1].se) {
				l = all[i - 1].se + 1, r = all[i].se;
			}
		}
		if (l != -1) printf("%d %d\n", l, r);
		else printf("-1\n");
	}
	return 0;
}