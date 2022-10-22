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

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 24e5;
const int lg = 16;
const int inf = 1e9;
int n, a[maxn + 5], b[maxn + 5], p[maxn + 5], dis[maxn + 5], pre[maxn + 5], rev[maxn + 5];
struct Edge {
	int to, nxt;
	bool w;
}e[maxn * lg + 5];
int cnt, head[maxn + 5];
inline void add(int u, int v, int w) {
	e[++ cnt] = {v, head[u], w}, head[u] = cnt;
}
void bfs() {
	deque<int> q; 
	rep(i, 1, maxn) dis[i] = inf;
	q.push_front(n), dis[n] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop_front();
		if(u <= a[u]) {
			cout << dis[u] + 1 << '\n';
			vector<int> ans; ans.push_back(0);
			while(u != n) {
				if(rev[u]) ans.push_back(rev[u]);
				u = pre[u];
			}
			reverse(all(ans));
			for(auto x : ans) cout << x << ' ';
			exit(0);
		}
		trv(i, u, v) if(dis[v] > dis[u] + e[i].w) {
			dis[v] = dis[u] + e[i].w;
			pre[v] = u;
			if(e[i].w) q.push_back(v);
			else q.push_front(v);
		}
	}
}
struct Segment {
	#define ls (u << 1)
	#define rs (u << 1 | 1)
	void build(int u, int l, int r) {
		if(l == r) return add(u + n, p[l], 0), rev[u + n] = l, void();
		int mid = l + r >> 1;
		add(u + n, ls + n, 0), add(u + n, rs + n, 0);
		build(ls, l, mid), build(rs, mid + 1, r);
	}
	void link(int u, int l, int r, int ql, int qr, int p) {
		if(l >= ql && r <= qr) {
			add(p, u + n, 1);
			return ;
		}
		int mid = l + r >> 1;
		if(qr <= mid) link(ls, l, mid, ql, qr, p);
		else if(ql > mid) link(rs, mid + 1, r, ql, qr, p);
		else link(ls, l, mid, ql, qr, p), link(rs, mid + 1, r, ql, qr, p);
	}
}t;
int main() {
//	freopen("in.txt", "r", stdin);
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n) b[i] = read(), p[i] = min(n, i + b[i]);
	t.build(1, 1, n);
	rep(i, 1, n) t.link(1, 1, n, max(1, i - a[i]), i, i);
	bfs();
	cout << "-1\n";
	return 0;
}