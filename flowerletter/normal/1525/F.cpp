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
const int maxn = 50;
const int maxm = 7500;
const ll inf = 1e18;

int n, m, k, u, v, p[maxn + 5], pre[maxn + 5][maxn + 5];
int x[maxn + 5], y[maxn + 5];
ll dp[maxn + 5][maxn + 5];
vector<int> ans;
struct Dinic {
	int s, t, exist[maxn * 2 + 5], dep[maxn * 2 + 5];
	int cnt = 1, head[maxn * 2 + 5], w[maxm * 2 + 5], cur[maxn * 2 + 5];
	struct Edge {
		int to, next, w;
	}e[maxm * 2 + 5];
	inline void add(int u, int v, int w) {
		e[++cnt] = (Edge) {v, head[u], w}, head[u] = cnt;
		e[++cnt] = (Edge) {u, head[v], 0}, head[v] = cnt;
	}
	bool bfs() {
		memset(dep, 0, sizeof dep);
		memcpy(cur, head, sizeof cur);
		queue<int> q;q.push(s), dep[s] = 1;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if(!exist[u]) {dep[u] = -1; continue;}
			trv(i, u, v) if(!dep[v] && e[i].w) dep[v] = dep[u] + 1, q.push(v);
		}
		return dep[t];
	}
	int dfs(int u, int flow) {
		if(u == t) return flow;
		int res = flow;
		for(int &i = cur[u], v = e[i].to; i; v = e[i = e[i].next].to)
			if(e[i].w && dep[v] == dep[u] +1) {
			int k = dfs(v, min(e[i].w, res));
			res -= k, e[i].w -= k, e[i ^ 1].w += k;
		}
		return flow - res;
	}
	int maxflow() {
		rep(i, 1, cnt) w[i] = e[i].w;
		int res = 0;
		while(bfs()) res += dfs(s, inf);
		rep(i, 1, cnt) e[i].w = w[i];
		return res;
	}
}G;
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &k), G.exist[G.s = 2 * n + 1] = 1, G.exist[G.t = 2 * n + 2] = 1;  
	rep(i, 1, n) G.exist[i] = G.exist[i + n] = 1, G.add(G.s, i, 1), G.add(i + n, G.t, 1);
	rep(i, 1, m) scanf("%d%d", &u, &v), G.add(v, n + u, 1);
	rep(i, 1, k) scanf("%d%d", &x[i], &y[i]);
	int nw = n - G.maxflow(), del = max(0, k + 1 - nw);
	rep(i, 1, del) {
		rep(j, 1, 2 * n) if(G.exist[j]) {
			G.exist[j] = 0;
			int nxt = n - G.maxflow();
			if(nxt >= nw + i) {p[i] = j; break;}
			G.exist[j] = 1;
		}
	}
	rep(i, 0, k) rep(j, 0, del) dp[i][j] = -inf; dp[0][0] = 0;
	rep(i, 1, k) rep(j, max(0, i - nw + 1), del) rep(k, 0, j) { 
		if(chkmx(dp[i][j], dp[i - 1][j - k] + max(0ll, x[i] - 1ll * y[i] * k))) pre[i][j] = k;
	}
	cout << k + del << '\n';
	int j = del, tot = 1;
	per(i, k, 1) ans.push_back(pre[i][j]), j -= pre[i][j];
	reverse(all(ans));
	rep(i, 1, k) {
		rep(j, 1, ans[i - 1]) cout << ((p[tot] <= n) ? (-p[tot]) : (p[tot] - n)) << ' ', tot ++;
		cout << "0 ";
	}
	return 0;
}