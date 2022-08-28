#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
char s[100010], t[100010];
vector < int > pos[150];
int c[100010];
void add(int x, int k) {
	for (; x <= n; x += x & -x) c[x] += k;
}
int query(int x) {
	int ans = 0;
	for (; x; x -= x & -x) ans += c[x];
	return ans;
}
void rmain() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	for (int i = 'a'; i <= 'z'; i++) pos[i].clear();
	for (int i = 1; i <= n; i++) c[i] = 0;
	for (int i = n; i > 0; i--) pos[s[i]].push_back(i), add(i, 1);
	ll ans = LLONG_MAX, cur = 0;
	for (int i = 1; i <= n; i++) {
		if (cur > ans) break;
		int qwq = 0x3f3f3f3f;
		for (int c = 'a'; c < t[i]; c++) if (pos[c].size()) qwq = min(qwq, pos[c].back());
		if (qwq <= n) ans = min(ans, cur + query(qwq - 1));
		if (pos[t[i]].size()) {
			int p = pos[t[i]].back();
			pos[t[i]].pop_back();
			cur += query(p - 1);
			add(p, -1);
		}
		else break;
	}
	if (ans == LLONG_MAX) puts("-1");
	else printf("%lld\n", ans);
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}