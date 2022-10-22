#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppp;

vector <ppp> all;
long long v1[100010], v2[100010];
int T[200010];

void modify(int x, int v) {while (x <= 200005) T[x] += v, x += x & -x;}

int query(int x) {int res = 0; while (x) res += T[x], x -= x & -x; return res;}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		if (x > y) swap(x, y);
		all.push_back(mp(mp(x, y), i));
	}
	sort(all.rbegin(), all.rend());
	memset(T, 0, sizeof(T));
	for (int i = 0; i < all.size(); i++) v1[all[i].se] = query(all[i].fi.se), modify(all[i].fi.se, 1);
	memset(T, 0, sizeof(T));
	for (int i = 0; i < all.size(); i++) v2[all[i].se] = i - query(all[i].fi.se), modify(all[i].fi.fi, 1);
	sort(all.begin(), all.end());
	memset(T, 0, sizeof(T));
	for (int i = 0; i < all.size(); i++) v2[all[i].se] += query(all[i].fi.fi), modify(all[i].fi.se, 1);
	memset(T, 0, sizeof(T));
	for (int i = 0; i < all.size(); i++) v2[all[i].se] += i - query(all[i].fi.se), modify(all[i].fi.se, 1);
	long long ans = 1ll * n * (n - 1) * (n - 2) / 6, sum = 0;
	for (int i = 0; i < n; i++) ans -= v1[i] * v2[i], sum += (v1[i] + v2[i]) * (n - v1[i] - v2[i] - 1);
	ans -= sum / 2;
	printf("%lld\n", ans);
	return 0;
}