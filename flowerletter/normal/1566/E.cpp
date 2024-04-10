/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 2e5;
int T, n, u, v, ans, dep[maxn + 5], son[maxn + 5], cnt[maxn + 5], fa[maxn + 5];
vector<int> g[maxn + 5];
set<P> s;
void dfs(int u, int par) {
	dep[u] = dep[par] + 1, fa[u] = par, son[u] = sz(g[u]) - (u != 1);
	if(sz(g[u]) == 1 && u != 1) {
		cnt[par] ++;
		if(cnt[par] == son[par]) {
			for(auto v : g[par]) if(v != fa[par]) s.insert({dep[v], v});
		}
		ans ++;
	}
	for(auto v : g[u]) if(v != par) {
		dfs(v, u);
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		s.clear();
		cin >> n;
		rep(i, 1, n) g[i].clear();
		rep(i, 1, n) cnt[i] = son[i] = 0;
		rep(i, 2, n) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
		ans = 0, dfs(1, 0);
		while(!s.empty()) {
			P u = *s.rbegin();
			int x = fa[u.se];
			if(x == 1) break;
			for(auto v : g[x]) if(v != fa[x]) s.erase({dep[v], v});
			ans --;
			son[fa[x]] --;
			if(son[fa[x]] == 0) {
				ans ++;
				if(fa[x] != 1) {
					cnt[fa[fa[x]]] ++;
					if(son[fa[fa[x]]] == cnt[fa[fa[x]]]) {
						for(auto v : g[fa[fa[x]]]) if(v != fa[fa[fa[x]]]) if(!cnt[v]) {
							s.insert({dep[v], v});
						}
					}
				}
			}
			else if(son[fa[x]] == cnt[fa[x]]) {
				for(auto v : g[fa[x]]) if(v != fa[fa[x]]) if(!cnt[v]) {
					s.insert({dep[v], v});
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}