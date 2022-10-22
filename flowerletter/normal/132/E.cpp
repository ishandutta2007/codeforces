#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;
const int maxn = 250;
const int maxm = 1e4;
const int inf = 1e9;
int n, m, a[maxn + 5], id[maxn + 5], lst[maxn + 5], getnew[maxn + 5], use[maxn + 5];
vector<int> pos[maxn + 5];
vector<int> st, del[maxn + 5];
struct Edge {
	int to, nxt, f, w;
};
struct Flow {
	int cnt = 1, head[maxn + 5];
	int n, s, t, low[maxn + 5], cur[maxn + 5], used[maxn + 5], vis[maxn + 5];
	Edge e[maxm + 5];
	void add(int u, int v, int f, int w) {
		e[++ cnt] = {v, head[u], f, w}, head[u] = cnt;
		e[++ cnt] = {u, head[v], 0, -w}, head[v] = cnt;
	}
	bool spfa() {
		queue<int> q;
		rep(i, 1, n) low[i] = inf, used[i] = 0, cur[i] = head[i];
		q.push(s), low[s] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop(), used[u] = 0;
			trv(i, u, v) if(e[i].f && low[v] > low[u] + e[i].w) {
				low[v] = low[u] + e[i].w;
				if(!used[v]) q.push(v), used[v] = 1;
			}
		}
		return low[t] != inf;
	}
	int dfs(int u, int flow) {
		if(u == t) return flow;
		vis[u] = 1;int ret = flow;
		for(int &i = cur[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if(low[v] == low[u] + e[i].w && e[i].f && !vis[v]) {
				int k = dfs(v, min(e[i].f, ret));
				ret -= k, e[i].f -= k, e[i ^ 1].f += k;
				if(!ret) break;
			}
		}
		vis[u] = 0;
		return flow - ret;
	}
	P mincostmaxflow() {
		P x = {0, 0};
		while(spfa()) {
			int cur = dfs(s, inf);
			x.fi += cur, x.se += cur * low[t];
		}
		return x;
	}
}d;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int ret = 0;
	rep(i, 1, n) cin >> a[i], st.pb(a[i]), ret += __builtin_popcount(a[i]);
	sort(all(st)), st.erase(unique(all(st)), st.end());
	rep(i, 1, n) {
		a[i] = lower_bound(all(st), a[i]) - st.begin() + 1;
		pos[a[i]].pb(i);
	}
	d.s = 1, d.t = d.n = n + 1;
	rep(i, 1, n) getnew[i] = 1, d.add(i, i + 1, m - 1, 0);
	rep(i, 1, n) {
		rep(j, 1, sz(pos[i]) - 1) {
			int u = pos[i][j - 1], v = pos[i][j];
			lst[v] = u;
			if(u == v - 1) {
				getnew[v] = 0;
				ret -= __builtin_popcount(st[i - 1]);
			}
			else {
				id[v] = d.cnt + 1;
				d.add(u + 1, v, 1, -__builtin_popcount(st[i - 1]));
			}
		}
		if(!pos[i].empty()) del[pos[i].back()].pb(i);
	}
	P x = d.mincostmaxflow();
	int cost = ret + x.se;
	rep(i, 1, n) if(id[i]) {
		if(!d.e[id[i]].f) {
			getnew[i] = 0;
		}
		else {
			del[lst[i]].pb(a[i]);
		}
	}
	vector<char> s(m);
	vector<string> ans; 
	iota(all(s), 'a');
	rep(i, 1, n) {
		if(getnew[i]) {
			assert(!s.empty());
			use[a[i]] = s.back();
			s.pop_back();
			function<string(int)> getnumber = [&] (int x) {
				string s = ""; 
				while(x) s = (char)(x % 10 + '0') + s, x /= 10;
				return s;
			};
			ans.pb((char)(use[a[i]]) + (string)"=" + getnumber(st[a[i] - 1]) + "\n");
		}
		ans.pb((string)"print(" + (char)(use[a[i]]) + ")\n");
		for(auto x : del[i]) {
			if(use[x]) {
				s.pb(use[x]);
				use[x] = 0;
			}
		}
	}
	cout << sz(ans) << ' ' << cost << '\n';
	for(auto x : ans) cout << x;
	return 0;
}