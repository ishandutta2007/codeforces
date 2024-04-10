#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, string> pis;

int main () {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	if (k > 4 * n * m - 2 * n - 2 * m) {
		printf("NO\n");
		return 0;
	}
	vector <pis> all;
	for (int i = 0; i < n - 1; i++) {
		all.push_back(mp(min(m - 1, k), "R"));
		k -= min(m - 1, k);
		if (k == 0) goto END;
		all.push_back(mp(min(m - 1, k), "L"));
		k -= min(m - 1, k);
		if (k == 0) goto END;
		all.push_back(mp(min(1, k), "D"));
		k -= min(1, k);
		if (k == 0) goto END;
	}
	all.push_back(mp(min(m - 1, k), "R"));
	k -= min(m - 1, k);
	if (k == 0) goto END;
	for (int i = m - 1; i >= 1; i--) {
		all.push_back(mp(min(n - 1, k), "U")), k -= min(n - 1, k);
		if (k == 0) goto END;
		all.push_back(mp(min(n - 1, k), "D")), k -= min(n - 1, k);
		if (k == 0) goto END;
		all.push_back(mp(min(1, k), "L")), k -= min(1, k);
		if (k == 0) goto END;
	}
	all.push_back(mp(min(n - 1, k), "U")), k -= min(n - 1, k);
	END:;
	assert(k == 0), assert(all.size() <= 3000);
	printf("YES\n");
	int tot = 0;
	for (int i = 0; i < all.size(); i++) {
		if (all[i].fi != 0) tot++;
	} 
	printf("%d\n", tot);
	for (int i = 0; i < all.size(); i++) {
		if (all[i].fi) printf("%d %s\n", all[i].fi, all[i].se.c_str());
	}
	return 0;
}