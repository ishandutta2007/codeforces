#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
mt19937_64 hua(time(0));
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int inf = 1e9;
const int maxn = 5e5;
const int lg = 40;
int q, ans[maxn + 5];
struct SGTmerge {
	int ls[maxn * lg], rs[maxn * lg];
	int rt[maxn + 5], nodecnt;
	int merge(int u, int v) {
		if(!u || !v) return u | v;
		ls[u] = merge(ls[u], ls[v]);
		rs[u] = merge(rs[u], rs[v]);
		return u;
	}
	void insert(int &u, int l, int r, int p) {
		if(!u) u = ++nodecnt;
		if(l == r) return ;
		int mid = l + r >> 1;
		if(p <= mid) insert(ls[u], l, mid, p);
		else insert(rs[u], mid + 1, r, p);
	}
	void dfs(int u, int l, int r, int col) {
		if(!u) return ;
		if(l == r) return ans[l] = col, void();
		int mid = l + r >> 1;
		dfs(ls[u], l, mid, col), dfs(rs[u], mid + 1, r, col);
	}
}ds;
int main() {
	//freopen("in.txt", "r", stdin);
	q = read();
	int tot = 0;
	rep(i, 1, q) {
		int opt = read();
		if(opt == 1) {
			int x = read();
			ds.insert(ds.rt[x], 1, q, ++tot);
		}
		else {
			int x = read(), y = read();
			if(x == y) continue;
			ds.rt[y] = ds.merge(ds.rt[y], ds.rt[x]), ds.rt[x] = 0;
		}
	}
	rep(i, 1, maxn) ds.dfs(ds.rt[i], 1, q, i);
	rep(i, 1, tot) cout << ans[i] << " \n"[i == tot];
	return 0;
}