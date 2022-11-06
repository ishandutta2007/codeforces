//Author: SBHeltion
//Date: 2019-06-22
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200000;
int maxx[maxn << 2], added[maxn << 2];
int a[maxn], b[maxn], inf = 1000000;
#define ls (v << 1)
#define rs ((v << 1) | 1)
#define tm ((tl + tr) >> 1)
void add(int v, int x){
	maxx[v] += x;
	added[v] += x;
}
void push_down(int v){
	add(ls, added[v]);
	add(rs, added[v]);
	added[v] = 0;
}
void add(int v, int tl, int tr, int L, int R, int x){
	if(tl >= L and tr <= R) add(v, x);
	else{
		push_down(v);
		if(L <= tm) add(ls, tl, tm, L, R, x);
		if(R > tm) add(rs, tm + 1, tr, L, R, x);
		maxx[v] = max(maxx[ls], maxx[rs]);
	}
}
int query(int v, int tl, int tr){
	if(tl == tr) return tm;
	push_down(v);
	if(maxx[rs] > 0) return query(rs, tm + 1, tr);
	return query(ls, tl, tm);
}
void debug(int v, int tl, int tr){
	cout << "debug" << v << " " << tl << " " << tr << " " << maxx[v] << endl;
	if(tl < tr){
		debug(ls, tl, tm);
		debug(rs, tm + 1, tr);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		add(1, 1, inf, 1, a[i], 1);
	}
	for(int i = 1; i <= m; i += 1){
		cin >> b[i];
		add(1, 1, inf, 1, b[i], -1);
	}
	int q;
	cin >> q;
	for(int j = 1; j <= q; j += 1){
		int t, i, x;
		cin >> t >> i >> x;
		if(t == 1){
			add(1, 1, inf, 1, a[i], -1);
			add(1, 1, inf, 1, a[i] = x, 1);
		}
		if(t == 2){
			add(1, 1, inf, 1, b[i], 1);
			add(1, 1, inf, 1, b[i] = x, -1);
		}
		if(maxx[1] <= 0) cout << "-1\n";
		else cout << query(1, 1, inf) << "\n";
	}
	return 0;
}