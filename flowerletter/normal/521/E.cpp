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

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 2e5; 
int n, m, cnt, u[maxn + 5], v[maxn + 5], dep[maxn + 5], fa[maxn + 5], head[maxn + 5];
P a[maxn + 5];
struct Edge {
	int to, next;
}e[maxn * 2 + 5];
inline vector<int> operator + (vector<int> s, vector<int> t) {
	for(auto u : t) s.push_back(u);
	return s;
}
inline vector<int> operator ~ (vector<int> s) {
	reverse(all(s));
	return s;
}
void add(int u, int v) {
	e[++cnt] = (Edge) {v, head[u]}, head[u] = cnt;
}
void dfs(int u, int par) {
	dep[u] = dep[fa[u] = par] + 1;
	trv(i, u) {
		int v = e[i].to;
		if(dep[v]) continue;
		dfs(v, u);
	}
}
vector<int> get(int u, int v) {
	vector<int> s;
	while(u != v) s.push_back(u), u = fa[u];
	return s; 
}
int find(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	while(dep[u] > dep[v]) u = fa[u];
	while(u != v) u = fa[u], v = fa[v];
	return u;
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d%d", &u[i], &v[i]), add(u[i], v[i]), add(v[i], u[i]);
	rep(i, 1, n) if(!dep[i]) dfs(i, 0);
	rep(i, 1, m) if(fa[u[i]] != v[i] && fa[v[i]] != u[i]) {
		if(dep[u[i]] < dep[v[i]]) swap(u[i], v[i]);
		int x = u[i];
		while(x != v[i]) {
			if(a[x] != P{0, 0}) {
				int y = v[i], z = a[x].fi, w = a[x].se;
				x = u[i];
				int ans1 = find(x, z), ans2 = dep[y] < dep[w] ? w : y;
				puts("YES");
				vector<int> path[3];
				path[0] = get(ans1, fa[ans2]);
				path[1] = ~get(x, fa[ans1]) + ~get(ans2, fa[y]);
				path[2] = ~get(z, fa[ans1]) + ~get(ans2, fa[w]);
				cout << sz(path[0]) << ' ';for(auto u : path[0]) printf("%d ", u);puts("");
				cout << sz(path[1]) << ' ';for(auto u : path[1]) printf("%d ", u);puts("");
				cout << sz(path[2]) << ' ';for(auto u : path[2]) printf("%d ", u);puts(""); 
				return 0;
			}
			else a[x] = {u[i], v[i]};
			x = fa[x];
		}
	}
	puts("NO");
	return 0;
}