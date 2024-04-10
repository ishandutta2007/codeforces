#include<bits/stdc++.h>
#define ls (v << 1)
#define rs (v << 1 | 1)
#define tm ((tl + tr) >> 1)
using namespace std;
constexpr int maxn = 540000;
constexpr int maxk = 54; 
struct edge{
	int u, v;
}e[maxn];
struct QUE{
	int e, c;
}que[maxn];
int nxt[maxn], pos[maxn], color[maxn];
struct DSU{
	int pt[maxn], py[maxn];
	DSU(){memset(pt, -1, sizeof pt);}
	pair<int, int> getp(int u, int y = 0){
		return pt[u] < 0 ? make_pair(u, y) : getp(pt[u], y ^ py[u]);
	}
}dsu[maxk];
namespace segtree{
	vector<QUE> ques[maxn << 2];
	void add(int v, int tl, int tr, int L, int R, QUE q){
		if(tl >= L and tr <= R) ques[v].push_back(q);
		else{
			if(L <= tm) add(ls, tl, tm, L, R, q);
			if(R > tm) add(rs, tm + 1, tr, L, R, q);
		}
	}
	void solve(int v, int tl, int tr, int n){
		stack<pair<int*, int>> back; 
		for(const QUE &q : ques[v]){
			auto u = dsu[q.c].getp(e[q.e].u), v = dsu[q.c].getp(e[q.e].v);
			if(u.first != v.first){
				if(dsu[q.c].pt[u.first] < dsu[q.c].pt[v.first]) swap(u, v);
				back.push(make_pair(&dsu[q.c].pt[v.first], dsu[q.c].pt[v.first]));
				back.push(make_pair(&dsu[q.c].pt[u.first], dsu[q.c].pt[u.first]));
				back.push(make_pair(&dsu[q.c].py[u.first], dsu[q.c].py[u.first]));
				dsu[q.c].pt[v.first] += dsu[q.c].pt[u.first];
				dsu[q.c].pt[u.first] = v.first;
				dsu[q.c].py[u.first] = u.second ^ v.second ^ 1;
			}
		}
		if(tl == tr){
			const auto &q = que[tm];
			auto u = dsu[q.c].getp(e[q.e].u), v = dsu[q.c].getp(e[q.e].v);
			if(u != v){
				cout << "YES" << endl;
				if(nxt[tm] - 1 >= tm + 1) add(1, 1, n, tm + 1, nxt[tm] - 1, que[tm]);
				color[q.e] = q.c;
			}
			else{
				cout << "NO" << endl;
				if(color[q.e]) if(nxt[tm] - 1 >= tm + 1) add(1, 1, n, tm + 1, nxt[tm] - 1, {q.e, color[q.e]});
			}
		}
		else{
			solve(ls, tl, tm, n);
			solve(rs, tm + 1, tr, n);
		}
		for(; back.size(); back.pop())
			*back.top().first = back.top().second;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, q, k;
	cin >> n >> m >> k >> q;
	for(int i = 1; i <= m; i += 1) cin >> e[i].u >> e[i].v;
	for(int i = 1; i <= q; i += 1) cin >> que[i].e >> que[i].c;
	fill(pos + 1, pos + m + 1, q + 1);
	for(int i = q; i >= 1; i -= 1){
		nxt[i] = pos[que[i].e];
		pos[que[i].e] = i;
	}
	segtree::solve(1, 1, q, q);
	return 0; 
}