//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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
ll gcd(ll a, ll b) {
	if (b) return gcd(b, a % b);
	else return a;
}

using namespace std;

int dfn[maxn], low[maxn], ins[maxn], st[maxn], id[maxn];
int top, cnt, wtf, n, m, q;
ll len[maxn], lab[maxn];
vector<pair<int, int>> e[maxn];
void tarjan(int u) {
	dfn[u] = low[u] = ++wtf;
	ins[u] = 1;
	st[++top] = u;
	for (auto p : e[u]) {
		int v = p.fi;
		if (!dfn[v]) {
			lab[v] = lab[u] + p.se;
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = min(low[u], low[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++cnt;
		len[cnt] = 0;
		while (1) {
			id[st[top]] = cnt;
			ins[st[top]] = 0;
			if (st[top--] == u) break;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back({v, w});
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int u = 1; u <= n; u++) {
		for (auto p : e[u]) {
			int v = p.fi;
			if (id[u] != id[v]) continue;
			ll d = lab[u] + p.se - lab[v];
			if (d < 0) d = -d;
			len[id[u]] = gcd(len[id[u]], d);
		}
	}
	for (int i = 1; i <= cnt; i++) {
		fprintf(stderr, "cyc %d %lld\n", i, len[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int v, s, t;
		scanf("%d%d%d", &v, &s, &t);
		if (s == 0) {
			puts("YES");
			continue;
		}
		if (len[id[v]] == 0) {
			puts("NO");
			continue;
		}
		ll d = gcd(len[id[v]], t);
		puts(s % d == 0 ? "YES" : "NO");
	}
}