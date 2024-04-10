#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> pip;

set <pip> edge;
map <pii, int> wei;
map <pip, int> cnt;
vector <pip> alive;
set <pii> from[100010];

bool OK2(pii a, pii b) {return a.fi != b.fi && a.se != b.se && a.fi != b.se && a.se != b.fi;}

bool cmp(pip a, pip b) {
	return a.se < b.se;
}

bool OK3(pii a, pii b, pii c) {
	return a.fi != b.fi || a.se != c.fi || b.se != c.se;
}

long long Solve() {
	alive.clear();
	for (auto it : edge) {
		alive.push_back(it);
		if (alive.size() == 6) break;
	}
	sort(alive.begin(), alive.end(), cmp);
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 0; i < alive.size(); i++) {
		pip it = alive[i];
		for (int j = i + 1; j < alive.size(); j++) {
			pip jt = alive[j];
			if (OK2(it.se, jt.se)) ans = min(ans, (long long)it.fi + jt.fi);
			for (int k = j + 1; k < alive.size(); k++) {
				pip kt = alive[k];
				if (OK3(it.se, jt.se, kt.se)) ans = min(ans, (long long)it.fi + jt.fi + kt.fi);
			}
		}
	}
	return ans;
}

void ERA(int x, int y, int w) {
	if (x > y) swap(x, y);
	if (cnt[mp(w, mp(x, y))] == 2) edge.erase(mp(w, mp(x, y)));
	cnt[mp(w, mp(x, y))]--;
}

void INS(int x, int y, int w) {
	if (x > y) swap(x, y);
	cnt[mp(w, mp(x, y))]++;
	if (cnt[mp(w, mp(x, y))] == 2) edge.insert(mp(w, mp(x, y)));
}

void Era(int x) {
	int k = 3;
	for (auto it : from[x]) {
		k--;
		ERA(it.se, x, it.fi);
		if (!k) break;
	}
}

void Ins(int x) {
	int k = 3;
	for (auto it : from[x]) {
		k--;
		INS(it.se, x, it.fi);
		if (!k) break;
	}
}

void InsEdge(int x, int y, int w) {Era(x), Era(y), from[x].insert(mp(w, y)), from[y].insert(mp(w, x)), Ins(x), Ins(y);}

void EraEdge(int x, int y, int w) {Era(x), Era(y), from[x].erase(mp(w, y)), from[y].erase(mp(w, x)), Ins(x), Ins(y);}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		if (x > y) swap(x, y);
		InsEdge(x, y, w), wei[mp(x, y)] = w;
	}
	printf("%lld\n", Solve());
	int q; scanf("%d", &q);
	while (q--) {
		int op, x, y, w; scanf("%d%d%d", &op, &x, &y);
		if (x > y) swap(x, y);
		if (op == 1) scanf("%d", &w), InsEdge(x, y, w), wei[mp(x, y)] = w;
		else w = wei[mp(x, y)], EraEdge(x, y, w);
		printf("%lld\n", Solve());
	}
	return 0;
}