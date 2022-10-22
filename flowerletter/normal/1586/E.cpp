#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
const int maxn = 3e5;
int n, m, q, u, v, ans, sum, vis[maxn + 5], fa[maxn + 5], c[maxn + 5], dep[maxn + 5];
int qu[maxn + 5], qv[maxn + 5];
struct Edge {
	int to, next;
}e[maxn * 2 + 5];
int head[maxn + 5], cnt;
vector<int> g[maxn + 5];
void add(int u, int v) {
	e[++ cnt] = (Edge) {v, head[u]}, head[u] = cnt;
}
void dfs1(int u) {
	vis[u] = 1;
	for(auto v : g[u]) if(!vis[v]) {
		add(u, v), fa[v] = u, dep[v] = dep[u] + 1;
		dfs1(v);
	}
}
void dfs2(int u) {
	trv(i, u, v) dfs2(v), c[u] ^= c[v];
	if(c[u]) sum = 1;
}
void dfs3(int u) {
	int cnt = 0;
	trv(i, u, v) if(c[v]) dfs3(v), cnt ++;
	ans += (cnt & 1) ? - cnt / 2 : (1 - cnt / 2);
}
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	rep(i, 1, m) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
	dfs1(1);
	cin >> q;
	rep(i, 1, q) {
		cin >> u >> v;
		qu[i] = u, qv[i] = v;
		c[u] ^= 1, c[v] ^= 1;
	}
	dfs2(1);
	if(sum) {
		puts("NO");
		rep(i, 1, n) if(!c[i]) {
			int flag = 0;
			trv(j, i, v) if(c[v]) flag ++;
			if(flag) ans = 0, dfs3(i), sum += ans - (flag % 2 == 0);
		}
		cout << sum - 1 << '\n';
	}
	else {
		puts("YES");
		rep(i, 1, q) {
			vector<int> s, t;
			u = qu[i], v = qv[i];
			while(u != v) {
				if(dep[u] > dep[v]) {
					s.push_back(u);
					u = fa[u];
				}
				else {
					t.push_back(v);
					v = fa[v];
				}
			}
			cout << sz(s) + sz(t) + 1 << '\n';
			for(auto x : s) cout << x << ' ';
			cout << u << ' ';
			reverse(all(t));
			for(auto x : t) cout << x << ' '; puts("");
		}
	}
	return 0;
}