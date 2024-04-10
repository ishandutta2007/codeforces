#include <bits/stdc++.h>

using namespace std;

const int LG = 22;
const int MAXN = (1 << (LG + 1));

int a[MAXN];
bitset <MAXN> used, have;
int n, m;

void jfs(int u) {
	used[u] = true;
	if ((1 << n) <= u) {
	 	int v = u - (1 << n);
	 	if (!used[v]) jfs(v);	
	}
	else {
		int v = (1 << n) - 1 - u;
		if (have[v] && !used[v + (1 << n)]) jfs(v + (1 << n));
		for (int i = 0; i < n; ++i) {
			if (!((u >> i) & 1) && !used[u | (1 << i)]) jfs(u | (1 << i));
		}
	}
}

signed main() {
	scanf("%d %d\n", &n, &m);

	for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i) have[a[i]] = true;

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		if (!used[a[i] + (1 << n)]) {
			++ans;
			jfs(a[i] + (1 << n));
		}
	}

	printf("%d\n", ans);
	return 0;
}