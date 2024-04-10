#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> all;
int a[2010], b[2010], c[2010], d[2010];
pii st[2010]; int tp;

int main () {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[j] - a[i] >= 0 && d[j] - b[i] >= 0) all.push_back(mp(c[j] - a[i], d[j] - b[i]));
		}
	}
	sort(all.begin(), all.end());
	tp = 0, st[tp++] = mp(-1, 0x3f3f3f3f);
	for (int i = 0; i < all.size(); i++) {
		while (tp && st[tp - 1].se <= all[i].se) tp--;
		st[tp++] = all[i];
	}
	st[tp++] = mp(0x3f3f3f3f, -1);
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < tp - 1; i++) {
		ans = min(ans, st[i].fi + st[i + 1].se + 2);
	}
	cout << ans << endl;
	return 0;
}