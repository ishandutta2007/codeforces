//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
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

ll w[maxn];
int f[maxn], x,a[maxn],b[maxn];
set<pi> e[maxn];
set<pair<ll,int>> pw;
vi ans;
int n, m;

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
	scanf("%d%d%d", &n, &m, &x);
	ll s = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", w + i);
		w[i] -= x;
		f[i] = i;
		s += w[i];
		pw.insert({w[i], i});
	}
	if (s < -x) {
		puts("NO");
		return 0;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", a + i, b + i);
		e[a[i]].insert({b[i], i});
		e[b[i]].insert({a[i], i});
	}
	for (int i = 1; i <= n - 1; i++) {
		int u = pw.rbegin()->se;
		assert(find(u) == u);
		while (!e[u].empty() && find(e[u].begin()->fi) == u) {
			e[u].erase(e[u].begin());
		}
		assert(!e[u].empty());
		int v = find(e[u].begin()->fi);
		ans.pb(e[u].begin()->se);
		pw.erase({w[u], u});
		pw.erase({w[v], v});
		assert(w[u] + w[v] >= -x);
		if (e[u].size() < e[v].size()) swap(u, v);
		f[v] = u;
		w[u] += w[v];
		for (auto p : e[v]) e[u].insert(p);
		e[v].clear();
		pw.insert({w[u],u});
	}
	puts("YES");
	for (auto p : ans) {
		printf("%d ", p + 1);
	}
	puts("");
}