#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, q;
int OP[200010], L[200010], R[200010], X[200010];
int a[200010], bad[200010];
set <int> S;

namespace RMQ {
	int st[200010][18], lg[200010];
	void init() {
		lg[0] = -1;
		for (int i = 1; i <= n; i++) {
			lg[i] = lg[i >> 1] + 1;
			st[i][0] = a[i];
		}
		for (int j = 1; j < 18; j++) {
			for (int i = 1; i <= n; i++) {
				if (i + (1 << j) - 1 > n) continue;
				st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
		}
	}
	int query(int l, int r) {
		if (l > r) return -INF;
		int k = lg[r - l + 1];
		return max(st[l][k], st[r - (1 << k) + 1][k]);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &OP[i]);
		if (OP[i] == 0) scanf("%d%d%d", &L[i], &R[i], &X[i]);
		else scanf("%d", &X[i]);
	}
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++) {
		S.insert(i);
	}
	for (int i = 0; i < q; i++) {
		if (OP[i] == 0 && X[i] == 0) {
			int l = L[i], r = R[i];
			auto it = S.lower_bound(l);
			while (it != S.end() && *it <= r) a[*it] = i, it = S.erase(it);
		}
	}
	RMQ :: init();
	for (int i = 0; i < q; i++) {
		if (OP[i] == 0 && X[i] == 1) {
			int l = L[i], r = R[i];
			auto it = S.lower_bound(l);
			int x = *it; it++;
			if (it != S.end() && *it <= r) continue;
			int need = max(max(RMQ :: query(l, x - 1), RMQ :: query(x + 1, r)), i);
			a[x] = min(a[x], need), bad[x] = 1;
		}
	}
	for (int i = 0; i < q; i++) {
		if (OP[i] == 1) {
			int x = X[i];
			if (a[x] > i) printf("N/A\n");
			else if (bad[x]) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}