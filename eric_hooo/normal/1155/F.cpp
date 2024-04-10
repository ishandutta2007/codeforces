#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int fa[15];
int n;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool check(vector <pii> &v) {
	random_shuffle(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int tot = n;
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		for (int j = 0; j < v.size(); j++) {
			if (i == j) continue;
			if (find(v[j].fi) != find(v[j].se)) {
				fa[find(v[j].fi)] = find(v[j].se);
				tot--;
				if (tot == 1) break;
			}
		}
		if (tot != 1) return 0;
	}
	return 1;
}

int main () {
	srand((int)time(NULL));
	int m; scanf("%d%d", &n, &m);
	vector <pii> v;
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		v.push_back(mp(x, y));
	}
	int T = 0;
	vector <pii> cur = v;
	vector <pii> ans = v;
	while (clock() <= 1900) {
		if (T == 1000) {
			if (ans.size() > cur.size()) ans = cur;
			T = 0, cur = v;
		}
		int x = rand() % cur.size();
		vector <pii> tmp = cur; tmp.erase(tmp.begin() + x);
		if (check(tmp)) {
			if (rand() % 4 > 0) cur = tmp;
		}
		T++;
	}
	if (ans.size() > cur.size()) ans = cur;
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].fi, ans[i].se);
	}
	return 0;
}