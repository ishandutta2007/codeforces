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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 4e5;
const int inf = 1e9;
int n, m, tot, a[maxn + 5];
int num, col[maxn + 5], ins[maxn + 5], low[maxn + 5], dfn[maxn + 5];
int vis[maxn + 5], mx[maxn + 5], mn[maxn + 5], deg[maxn + 5], p[maxn + 5];
int cnt, head[maxn + 5];
struct Edge {int to, next;}e[maxn * 4 + 5];
vector<char> mp[maxn + 5];
vector<int> id[maxn + 5], s1, G[maxn + 5];
vector<P> s2;
stack<int> s;
inline void add(int u, int v) {
	e[++cnt] = (Edge) {v, head[u]}, head[u] = cnt; 
} 
void tarjan(int u) {
	static int ts = 0;
	ins[u] = 1, low[u] = dfn[u] = ++ ts, s.push(u);
	trv(i, u, v) {
		if(!dfn[v]) tarjan(v), chkmn(low[u], low[v]);
		else if(ins[v]) chkmn(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		col[u] = ++ num, ins[u] = 0;
		while(s.top() != u) {
			col[s.top()] = num;
			ins[s.top()] = 0;
			s.pop();
		} s.pop();
	}
}
void topsort() {
	queue<int> q;
	rep(i, 1, num) for(auto v : G[i]) deg[v] ++;
	rep(i, 1, num) if(!deg[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(vis[u]) {s2.push_back({vis[u], u});continue;}
		for(auto v : G[u]) if(-- deg[v] == 0) q.push(v);
	}
}
void dp() {
	queue<int> q;
	vector<int> p;
	rep(i, 1, num) deg[i] = 0;
	rep(i, 1, num) for(auto v : G[i]) deg[v] ++;
	rep(i, 1, num) if(!deg[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front(); q.pop(), p.push_back(u);
		for(auto v :G[u]) if(-- deg[v] == 0) q.push(v);
	}
	per(i, num - 1, 0) {
		int u = p[i];
		for(auto v : G[u]) chkmn(mn[u], mn[v]), chkmx(mx[u], mx[v]);
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	rep(i, 0, n + 1) mp[i].resize(m + 2), id[i].resize(m + 2);
	rep(i, 1, n) scanf("%s", mp[i].begin() + 1);
	rep(i, 1, m) scanf("%d", &a[i]);
	rep(i, 1, n) rep(j, 1, m) if(mp[i][j] == '#') id[i][j] = ++tot;
	rep(j, 1, m) {
		vector<int> last;
		int cnt = 0;
		per(i, n, 1) {
			if(id[i][j - 1]) last.push_back(id[i][j - 1]);
			if(id[i][j + 1]) last.push_back(id[i][j + 1]); 
			if(id[i][j]){
				if(++ cnt == a[j]) s1.push_back(id[i][j]);
				if(id[i - 1][j]) add(id[i][j], id[i - 1][j]);
				for(auto x : last) add(id[i][j], x);
				last.clear();
				last.push_back(id[i][j]);
			}
		}
	}
	rep(i, 1, tot) if(!dfn[i]) tarjan(i);
	rep(u, 1, tot) trv(i, u, v) if(col[u] != col[v]) G[col[u]].push_back(col[v]);
	rep(i, 1, num) sort(all(G[i])), G[i].erase(unique(all(G[i])), G[i].end()), mx[i] = -inf, mn[i] = inf;
	tot = 0; 
	rep(i, 0, sz(s1) - 1) vis[col[s1[i]]] = ++tot;
	topsort(), sort(all(s2));
	rep(i, 0, sz(s2) - 1) mx[s2[i].se] = mn[s2[i].se] = i + 1;
	dp();
	rep(i, 1, num) p[i] = i;
	sort(p + 1, p + num + 1, [&](int x, int y){return mn[x] < mn[y];});
	int nw = 1, i = 1, ans = 0;
	while(nw <= sz(s2)) { 
		int nxt = -1;
		while(i <= num && mn[p[i]] <= nw) chkmx(nxt, mx[p[i]]), i++;
		nw = nxt + 1, ans ++;
	}
	printf("%d\n", ans);
	return 0;
}