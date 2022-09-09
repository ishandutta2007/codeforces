#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 120000;
int p[maxn], sz[maxn], hs[maxn], dfn[maxn], top[maxn], vis[maxn];
#define ls (v << 1)
#define rs (v << 1 | 1)
#define tm ((tl + tr) >> 1)
namespace segtree{
	int sum[maxn << 2], mss[maxn << 2];
	bool marked[maxn << 2];
	void mark(int v, int tl, int tr){
		marked[v] = true;
		sum[v] = tl - tr - 1;
		mss[v] = -1;
	}
	void push_down(int v, int tl, int tr){
		if(marked[v]){
			mark(ls, tl, tm);
			mark(rs, tm + 1, tr);
			marked[v] = false;
		}
	}
	void push_up(int v){
		sum[v] = sum[ls] + sum[rs];
		mss[v] = max(mss[rs], sum[rs] + mss[ls]);
	}
	void add(int v, int tl, int tr, int p, int x){
		if(tl == tr) sum[v] = mss[v] += x;
		else{
			push_down(v, tl, tr);
			if(p <= tm) add(ls, tl, tm, p, x);
			else add(rs, tm + 1, tr, p, x);
			push_up(v);
		}
	}
	void mark(int v, int tl, int tr, int L, int R){
		if(tl >= L and tr <= R) mark(v, tl, tr);
		else{
			push_down(v, tl, tr);
			if(L <= tm) mark(ls, tl, tm, L, R);
			if(R > tm) mark(rs, tm + 1, tr, L, R);
			push_up(v);
		}
	}
	int res = -1, ss = 0;
	void query(int v, int tl, int tr, int L, int R){
		if(tl >= L and tr <= R){
			res = max(res, ss + mss[v]);
			ss += sum[v];
		}
		else{
			push_down(v, tl, tr);
			if(R > tm) query(rs, tm + 1, tr, L, R);
			if(L <= tm) query(ls, tl, tm, L, R);
			push_up(v);
		}
	}
}
int query(int u, int n){
	segtree::res = -1;
	segtree::ss = 0;
	for(; u; u = p[top[u]]) segtree::query(1, 1, n, dfn[top[u]], dfn[u]);
	return segtree::res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 2; i <= n; i += 1) cin >> p[i];
	for(int i = n; i >= 2; i -= 1) sz[p[i]] += sz[i] += 1;
	for(int i = 2; i <= n; i += 1) if(not hs[p[i]] or sz[hs[p[i]]] < sz[i]) hs[p[i]] = i;
	for(int i = 1; i <= n; i += 1)
		if(hs[p[i]] == i){
			dfn[i] = dfn[p[i]] + 1;
			top[i] = top[p[i]];
		}
		else{
			dfn[i] = dfn[p[i]] + sz[hs[p[i]]] + vis[p[i]] + 1;
			vis[p[i]] += sz[i];
			top[i] = i;
		}
	segtree::marked[1] = true;
	for(int t, v; q; q -= 1){
		cin >> t >> v;
		if(t == 1) segtree::add(1, 1, n, dfn[v], 1);
		else if(t == 2){
			segtree::mark(1, 1, n, dfn[v], dfn[v] + sz[v] - 1);
			int res = query(v, n);
			if(res >= 0) segtree::add(1, 1, n, dfn[v], - res - 1);
		}
		else cout << (query(v, n) >= 0 ? "black\n" : "white\n");
	}
	return 0; 
}