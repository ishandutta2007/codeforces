#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> from[100010];

void erase(int x, int y) {
	for (int i = 0; i < from[x].size(); i++) {
		if (from[x][i].fi == y) {
			swap(from[x][i], from[x].back());
			from[x].pop_back();
			return ;
		}
	}
}

int size[100010], maxj[100010], dep[100010], dist[100010];
vector <int> node;
int WW, LL, n;
int T[100010];
long long ans;

void modify(int x, int v) {
	while (x <= n + 5) T[x] += v, x += x & -x;
}

int query(int x) {
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

void dfs(int x, int last) {
	node.push_back(x), size[x] = 1, maxj[x] = 0;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, w = from[x][i].se;
		if (v == last) continue;
		dep[v] = dep[x] + 1, dist[v] = dist[x] + w, dfs(v, x);
		maxj[x] = max(maxj[x], size[v]), size[x] += size[v];
	}
}

int get_root(int x) {
	node.clear(), dep[x] = dist[x] = 0, dfs(x, x);
	int ans = -1;
	for (int i = 0; i < node.size(); i++) {
		int v = node[i];
		if (ans == -1) ans = v;
		else if (max(maxj[ans], size[x] - size[ans]) > max(maxj[v], size[x] - size[v])) ans = v;
	}
	return ans;
}

long long calc(int x, int L, int W) {
	node.clear(), dep[x] = L, dist[x] = W, dfs(x, x);
	vector <pii> all;
	for (int i = 0; i < node.size(); i++) {
		int v = node[i];
		all.push_back(mp(dist[v], dep[v]));
	}
	sort(all.begin(), all.end());
	int pos = 0;
	long long ans = 0;
	for (int i = all.size() - 1; i >= 0; i--) {
		while (pos < all.size() && all[pos].fi + all[i].fi <= WW) modify(all[pos].se + 1, 1), pos++;
		ans += query(max(0, LL - all[i].se + 1));
		if (all[i].fi * 2 <= WW && all[i].se * 2 <= LL) ans--;
	}
	while (pos--) modify(all[pos].se + 1, -1);
	return ans / 2;
}

void solve(int x) {
	int rt = get_root(x);
	ans += calc(rt, 0, 0);
	for (int i = 0; i < from[rt].size(); i++) {
		int v = from[rt][i].fi, w = from[rt][i].se;
		erase(v, rt);
		ans -= calc(v, 1, w);
		solve(v);
	}
}

int main () {
	scanf("%d%d%d", &n, &LL, &WW);
	for (int i = 2; i <= n; i++) {
		int p, c; scanf("%d%d", &p, &c);
		from[p].push_back(mp(i, c));
		from[i].push_back(mp(p, c));
	}
	solve(1);
	printf("%I64d\n", ans);
	return 0;
}