#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <long long, int> pli;

vector <int> from[300010];
vector <pii> all[300010];
int dep[300010];

struct Block {
	set <pli> *S;
	long long B;
	Block() {S = new set <pli>, B = 0;}
	void merge(Block tmp) {
		if (S->size() < tmp.S->size()) swap(S, tmp.S), swap(B, tmp.B);
		for (set <pli> :: iterator it = tmp.S->begin(); it != tmp.S->end(); it++) {
			S->insert(mp(it->fi + tmp.B - B, it->se));
		}
		tmp.S->clear();
	}
	void flush(int x) {
		while (S->size() && S->begin()->se >= x) {
			S->erase(S->begin());
		}
	}
};

long long ans;

Block dfs(int x, int last) {
	Block T;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dep[v] = dep[x] + 1;
		T.merge(dfs(v, x));
	}
	for (int i = 0; i < all[x].size(); i++) {
		int v = all[x][i].fi, c = all[x][i].se;
		T.S->insert(mp(c - T.B, dep[v]));
	}
	T.flush(dep[x]);
	if (x == 1) return T;
	if (!T.S->size()) {
		printf("-1\n");
		exit(0);
	}
	ans += T.S->begin()->fi + T.B, T.B = -T.S->begin()->fi;
	return T;
}

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	for (int i = 1; i <= m; i++) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		all[x].push_back(mp(y, c));
	}
	dfs(1, 1);
	printf("%I64d\n", ans);
	return 0;
}