#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
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
const int maxn = 3e5;
const int lg = 70;
int n, q, k, m, a[maxn + 5], nxt[maxn + 5], rt[maxn + 5];
vector<P> qry[maxn + 5];
inline int id(int i, int x) {return (i - 1) / k + 1 + (x - i) / k;}
struct ChairmenTree {
	int nodecnt, tag[maxn * lg], siz[maxn * lg], ls[maxn *lg], rs[maxn * lg];
	ll sum[maxn * lg];
	inline int newnode(int len, int v = 0) {
		int u;
		siz[u = ++nodecnt] = len;
		ls[u] = ls[v], rs[u] = rs[v], sum[u] = sum[v], tag[u] = tag[v];
		return u;
	}
	void pushup(int u) {
		sum[u] = sum[ls[u]] + sum[rs[u]];
	}
	void seta(int u, int k) {
		tag[u] = k;
		sum[u] = 1ll * siz[u] * k;
	}
	void pushdown(int u) {
		if(tag[u]) {
			seta(ls[u] = newnode((siz[u] + 1) / 2), tag[u]);
			seta(rs[u] = newnode(siz[u] / 2), tag[u]);
			tag[u] = 0;
		}
		else {
			ls[u] = newnode((siz[u] + 1) / 2, ls[u]);
			rs[u] = newnode(siz[u] / 2, rs[u]);
		}
	}
	void update(int &u, int v, int l, int r, int ql, int qr, int k) {
		u = newnode(r - l + 1, v);
		if(l >= ql && r <= qr) return seta(u, k), void();
		int mid = l + r >> 1; pushdown(u);
		if(qr <= mid) update(ls[u], ls[v], l, mid, ql, qr, k);
		else if(ql > mid) update(rs[u], rs[v], mid + 1, r, ql, qr, k);
		else update(ls[u], ls[v], l, mid, ql, qr, k), update(rs[u], rs[v], mid + 1, r, ql, qr, k);
		pushup(u);
	}
	ll query(int u, int l, int r, int ql, int qr) {
		if(!u) return 0;
		if(tag[u]) return 1ll * (min(r, qr) - max(l, ql) + 1) * tag[u]; 
		if(l >= ql && r <= qr) return sum[u];
		int mid = l + r >> 1;
		if(qr <= mid) return query(ls[u], l, mid, ql, qr);
		else if(ql > mid) return query(rs[u], mid + 1, r, ql, qr);
		else return query(ls[u], l, mid, ql, qr) + query(rs[u], mid + 1, r, ql, qr);
	}
}t;
void init() {
	stack<int> s; s.push(n + 1);
	per(i, n, 1) {
		while(a[s.top()] > a[i]) s.pop();
		nxt[i] = s.top();
		s.push(i);
	}
	deque<int> q;
	per(i, n, 1) {
		while(!q.empty() && q.front() > i + k) q.pop_front();
		while(!q.empty() && a[q.back()] > a[i]) q.pop_back();
		q.push_back(i);
		int ql = id(i, i + k), qr = id(i, nxt[q.front()] - 1);
		if(ql <= qr) t.update(rt[i], i + k <= n ? rt[i + k] : 0, 1, m, ql, qr, a[q.front()]);
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), q = read(), k = read(), m = id(1, n + 1);
	rep(i, 1, n) a[i] = read();
	init();
	rep(i, 1, q) {
		int l = read(), r = read();
		cout << t.query(rt[l], 1, m, 1, id(l, r)) + a[l] << '\n';
	}
	return 0;
}