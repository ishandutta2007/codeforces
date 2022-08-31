#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
int a[200010];
int ans[200010], fa[200010];
vector < int > pos[200010];
int gf(int a) { return fa[a] == a ? a : fa[a] = gf(fa[a]); }
void merge(int a, int b) {
	fa[gf(a)] = gf(b);
}
void rmain() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) pos[i].clear(), fa[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		pos[a[i]].push_back(i);
	}
	int cur = 0;
	if (n % 2 == 1) {
		for (int i = 1; i <= n; i++) if (pos[i].size() % 2 == 1) {
			if (pos[i].back() == (n + 1) / 2) swap(pos[i].front(), pos[i].back());
			if (pos[i].back() == (n + 1) / 2) return puts("NO"), void();
			ans[(n + 1) / 2] = pos[i].back();
			pos[i].pop_back();
			break;
		}
	}
	for (int i = 1; i <= n; i++) if (pos[i].size() % 2 == 1) {
		return puts("NO"), void();
	}
	else {
		while (pos[i].size()) {
			ans[++cur] = pos[i].back();
			pos[i].pop_back();
			ans[n - cur + 1] = pos[i].back();
			pos[i].pop_back();
		}
	}
	for (int i = 1; i <= n; i++) merge(i, ans[i]);
	for (int i = 1; i * 2 <= n; i++) {
		if (gf(i) != gf(n - i + 1)) {
			swap(ans[i], ans[n - i + 1]);
			merge(i, n - i + 1);
		}
	}
	for (int i = 1; i < n / 2; i++) {
		if (gf(i) != gf(i + 1)) {
			swap(ans[i], ans[n - i + 1]);
			swap(ans[i], ans[i + 1]);
			swap(ans[n - i + 1], ans[n - i]);
			merge(i, i + 1);
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}