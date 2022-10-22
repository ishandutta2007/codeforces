#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> from[13000];
int a[13000], b[1000010], alive[13000], val[13000];
int vis[3000010], TOTOT = 2333;
int X[1000010], Y[1000010];

int main () {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int x, y; scanf("%d%d", &x, &y);
		x--, y--;
		from[x].push_back(mp(y, i));
		from[y].push_back(mp(x, i));
		X[i] = x, Y[i] = y, val[x]++, val[y]++, b[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		TOTOT++;
		int p = 0, q = 0;
		for (int j = 0; j < from[i].size(); j++) {
			int v = from[i][j].fi, id = from[i][j].se;
			if (!alive[v]) continue;
			if (a[v]) p++;
			else q++;
			vis[val[v]] = TOTOT;
		}
		for (int j = val[i] - q; j <= val[i] + p; j++) {
			if (vis[j] != TOTOT) {
				p = max(0, j - val[i]);
				q = max(0, val[i] - j);
			}
		}
		for (int j = 0; j < from[i].size(); j++) {
			int v = from[i][j].fi, id = from[i][j].se;
			if (!alive[v]) continue;
			if (a[v]) {
				if (p) p--, a[v] = 0, b[id]++, val[i]++;
			} else {
				if (q) q--, a[v] = 1, b[id]--, val[i]--;
			}
		}
		alive[i] = 1;
	}
	vector <int> all;
	for (int i = 0; i < n; i++) {
		if (a[i]) all.push_back(i + 1);
	}
	printf("%d\n", (int)all.size());
	if (all.size()) {
		for (int i = 0; i < all.size(); i++) {
			printf("%d ", all[i]);
		}
		printf("\n");
	}
	for (int i = 0; i < k; i++) {
		printf("%d %d %d\n", X[i] + 1, Y[i] + 1, b[i]);
	}
	return 0;
}