/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}

const int maxn = 3e5;
const int lg = 20;
const int mod = 1e9 + 7;
int n, q, u, v, l, r, a[maxn + 5];
int top[maxn + 5], dep[maxn + 5], son[maxn + 5], fa[maxn + 5], size[maxn + 5];
int Root[maxn + 5];
ll pw[maxn + 5];
vector<int> G[maxn + 5];
struct Chairman {
	ll hash[maxn * lg];
	int Nodecnt, ls[maxn * lg], rs[maxn * lg];
	void insert(int &rt, int pre, int l, int r, int p) {
		hash[rt = ++Nodecnt] = hash[pre], ls[rt] = ls[pre], rs[rt] = rs[pre];
		if(l == r) return hash[rt] ^= 1, void();
		int mid = l + r >> 1;
		if(p <= mid) insert(ls[rt], ls[pre], l, mid, p);
		else insert(rs[rt], rs[pre], mid + 1, r, p);
		hash[rt] = (hash[ls[rt]] * pw[r - mid] % mod + hash[rs[rt]]) % mod;
	}
	int query(int u, int v, int l, int r, int L, int R) {
		if(hash[u] == hash[v]) return -1;
		if(l == r) return l;
		int mid = l + r >> 1;
		if(R <= mid) return query(ls[u], ls[v], l, mid , L, R);
		else if(L > mid) return query(rs[u], rs[v], mid + 1, r, L, R);
		else {
			int res = query(ls[u], ls[v], l, mid, L, R);
			if(res == -1) return query(rs[u], rs[v], mid + 1, r, L, R);
			else return res;
		}
	}
	void bug(int rt, int l, int r) {
		if(l == r) return printf("%d%c", hash[rt], " \n"[r == n]), void();
		int mid = l + r >> 1;
		bug(ls[rt], l, mid), bug(rs[rt], mid + 1, r);
	}
}mjy;
void dfs1(int u, int par) {
	dep[u] = dep[fa[u] = par] + 1, size[u] = 1;
	mjy.insert(Root[u], Root[par], 1, n, a[u]);
	for(auto v :  G[u]) {
		if(v == par) continue;
		dfs1(v, u);
		size[u] += size[v];
		if(size[v] > size[son[u]]) son[u] = v;  
	}
}
void dfs2(int u, int tpar) {
	top[u] = tpar;
	if(son[u]) dfs2(son[u], tpar);
	for(auto v: G[u]) {
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
int lca(int u, int v) {
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v; 
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &q);pw[0] = 1;
	rep(i, 1, n) scanf("%d", &a[i]), pw[i] = pw[i - 1] * 2 % mod;
	rep(i, 2, n) scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u);
	dfs1(1, 0), dfs2(1, 0);
	rep(i, 1, q) {
		scanf("%d%d%d%d", &u, &v, &l, &r);
		int w = lca(u, v);
		if(l <= a[w] && a[w] <= r) {
			int d;
			if(mjy.query(Root[u], Root[v], 1, n, a[w], a[w]) == -1)	printf("%d\n", a[w]);
			else if(l <= a[w] - 1 && (d = mjy.query(Root[u], Root[v], 1, n, l, a[w] - 1)) != -1) printf("%d\n", d);
			else if(a[w] + 1 <= r && (d = mjy.query(Root[u], Root[v], 1, n, a[w] + 1, r)) != -1) printf("%d\n", d);
			else puts("-1");
		}
		else printf("%d\n", mjy.query(Root[u], Root[v], 1, n, l, r));
	}
	return 0;
}