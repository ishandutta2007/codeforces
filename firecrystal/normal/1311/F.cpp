#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, x[N], v[N], d[N], tot;

/*

0 : < 0
1 : > 0
*/
typedef long long LL;
LL ans = 0, c[2][N];
struct E{
	int x, v;
	bool operator < (const E &b) const {
		return x < b.x;
	} 
} e[N];
LL inline ask(int x, int mod) {
	LL res = 0;
	for (; x; x -= x & -x) res += c[mod][x];
	return res;
}
void inline add(int x, LL k, int mod) {
	for (; x <= tot; x += x & -x) c[mod][x] += k;
}
int inline get(int x) {
	return lower_bound(d + 1, d + 1 + tot, x) - d;
}
LL inline query(int l, int r, int mod) {
	return ask(r, mod) - ask(l - 1, mod);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &e[i].x);
	d[++tot] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &e[i].v), d[++tot] = e[i].v;
	sort(e + 1, e + 1 + n);
	sort(d + 1, d + 1 + tot);
	tot = unique(d + 1, d + 1 + tot) - d - 1;
	int O = get(0);
	for (int i = 1; i <= n; i++) {
		int val = get(e[i].v);
		if (e[i].v < 0) {
			ans += query(1, val, 0) * e[i].x - query(1, val, 1);
		} else if(e[i].v > 0) {
			ans += query(1, val, 0) * e[i].x - query(1, val, 1);
		} else if(e[i].v == 0) {
			ans += query(1, O, 0) * e[i].x - query(1, O, 1);
		}
		add(val, 1, 0);
		add(val, e[i].x, 1);
	}
	printf("%lld\n", ans);
	return 0;
}