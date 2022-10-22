#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

priority_queue <pii> q;
vector <pii> query[200010];
int T[200010];
int ans[200010];
int n;
int a[200010];

void modify(int x, int y) {
	while (x <= n) T[x] += y, x += x & -x;
}

int sum(int x) {
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		q.push(mp(a[i], -i));
	}
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		query[x].push_back(mp(y, i));
	}
	for (int i = 1; i <= n; i++) {
		pii now = q.top(); q.pop();
		modify(-now.se, 1);
		for (int j = 0; j < query[i].size(); j++) {
			int x = query[i][j].fi, id = query[i][j].se;
			int l = 1, r = n;
			while (l < r) {
				int mid = l + r >> 1;
				if (sum(mid) >= x) r = mid;
				else l = mid + 1;
			}
			ans[id] = a[l];
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}