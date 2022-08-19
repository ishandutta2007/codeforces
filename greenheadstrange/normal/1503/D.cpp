//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {return x < y ? x = y, true : false;}
template <typename T> bool chkmin(T &x, T y) {return x > y ? x = y, true : false;}

using namespace std;

int n;
set<int> st[maxn * 2], v;
int cost[maxn], mate[maxn], col[maxn];
vi vc[5];
ll ksm(ll a, ll b) {
	if (!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if (b & 1) ns = ns * a % mod;
	return ns;
}

void build(int p, int l, int r) {
	for (int i = l; i <= r; i++) st[p].insert(mate[i]);
	if (l != r) {
		int m = (l + r) / 2;
		build(p * 2, l, m);
		build(p * 2 + 1, m + 1, r);
	}
}

void del(int p, int l, int r, int x, int v) {
	if (st[p].count(v)) st[p].erase(v);
	if (l != r) {
		int m = (l + r) / 2;
		if (x <= m) del(p * 2, l, m, x, v);
		else del(p * 2 + 1, m + 1, r, x, v);
	}
}

void query(int p, int l, int r, int xl, int xr, int yl, int yr) {
	if (xl > xr) return;
	if (l == xl && r == xr) {
		while (true) {
			auto it = st[p].lower_bound(yl);
			if (it == st[p].end() || *it > yr) break;
			int id = *it;
			v.insert(mate[id]);
			del(1, 1, n, mate[id], id);
		}
	} else {
		int m = (l + r) / 2;
		if (xr <= m) query(p * 2, l, m, xl, xr, yl, yr);
		else if (xl > m) query(p * 2 + 1, m + 1, r, xl, xr, yl, yr);
		else {
			query(p * 2, l, m, xl, m, yl, yr);
			query(p * 2 + 1, m + 1, r, m + 1, xr, yl, yr);
		}
	}
}
void dfs(int u) {
	v.clear();
	vc[col[u]].push_back(u);
	query(1, 1, n, 1, u - 1, n + 1, mate[u] - 1);
	query(1, 1, n, u + 1, n, mate[u] + 1, 2 * n);
	vi w;
	for (auto p : v) w.push_back(p);
	for (auto p : w) {
		col[p] = 3 - col[u];
		dfs(p);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		mate[a] = b;
		cost[a] = 0;
		mate[b] = a;
		cost[b] = 1;
		if (a > b) swap(a, b);
		if (a > n || b <= n) {
			puts("-1");
			return 0;
		}
	}
	build(1, 1, n);
	int ans = 0;
	for (int i = 1; i <= n; i++) if (col[i] == 0) {
			vc[1].clear();
			vc[2].clear();
			col[i] = 1;
			del(1, 1, n, i, mate[i]);
			dfs(i);
			int c0 = 0, c1 = 0;
			for (auto p : vc[1]) {
				c0 += cost[p];
				c1 += cost[mate[p]];
			}
			for (auto p : vc[2]) {
				c1 += cost[p];
				c0 += cost[mate[p]];
			}
			ans += min(c0, c1);
		}
	vi R[5];
	for (int i = 1; i <= n; i++) R[col[i]].push_back(mate[i]);
	for (int i = 1; i < R[1].size(); i++) if (R[1][i] > R[1][i - 1]) {
			puts("-1");
			return 0;
		}
	for (int i = 1; i < R[2].size(); i++) if (R[2][i] > R[2][i - 1]) {
			puts("-1");
			return 0;
		}
	printf("%d\n", ans);
}