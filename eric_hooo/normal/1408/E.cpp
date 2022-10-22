#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> ppp; 

vector <ppp> edge;
int a[100010], b[100010], fa[100010];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main () {
	int n, m; scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < m; i++) {
		int k; scanf("%d", &k);
		while (k--) {
			int x; scanf("%d", &x), x--;
			edge.push_back(mp(a[i] + b[x], mp(i, x + m)));
		}
	}
	sort(edge.begin(), edge.end()), reverse(edge.begin(), edge.end());
	for (int i = 0; i < n + m; i++) {
		fa[i] = i;
	}
	long long ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		int x = edge[i].se.fi, y = edge[i].se.se, w = edge[i].fi;
		if (find(x) == find(y)) {
			ans += w;
			continue;
		}
		fa[find(x)] = find(y);
	}
	printf("%I64d\n", ans);
	return 0;
}