//Author: Heltion
//Date: 09-05-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
#define ls (v << 1)
#define rs ((v << 1) | 1)
#define tm ((tl + tr) >> 1)
int pw[maxn];
struct node{
	int f[9], g[9];
}t[maxn << 2];
void update(int v, int tl, int tr, int p, int x){
	if(tl == tr){
		for(int i = 0; i < 9; i += 1){
			if(x / pw[i] % 10) t[v].f[i] = x;
			else t[v].f[i] = 1e9;
			t[v].g[i] = 1e9;
		}
		return;
	}
	if(p <= tm) update(ls, tl, tm, p, x);
	else update(rs, tm + 1, tr, p, x);
	for(int i = 0; i < 9; i += 1){
		int a[4];
		a[0] = t[ls].f[i];
		a[1] = t[ls].g[i];
		a[2] = t[rs].f[i];
		a[3] = t[rs].g[i];
		sort(a, a + 4);
		t[v].f[i] = a[0];
		t[v].g[i] = a[1];
	}
}
int f[9], g[9];
void query(int v, int tl, int tr, int L, int R){
	if(tl >= L and tr <= R){
		for(int i = 0; i < 9; i += 1){
			int a[4];
			a[0] = t[v].f[i];
			a[1] = t[v].g[i];
			a[2] = f[i];
			a[3] = g[i];
			sort(a, a + 4);
			f[i] = a[0];
			g[i] = a[1];
		}
		return;
	}
	if(L <= tm) query(ls, tl, tm, L, R);
	if(R > tm) query(rs, tm + 1, tr, L, R);
}
LL query(int n, int l, int r){
	for(int i = 0; i < 9; i += 1) f[i] = g[i] = 1e9;
	query(1, 1, n, l, r);
	int res = -1;
	for(int i = 0; i < 9; i += 1)
		if(f[i] < (int)1e9 and g[i] < (int)1e9)
			if(res == -1 or f[i] + g[i] < res) res = f[i] + g[i];
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	for(int i = 0; i < 9; i += 1) pw[i] = i ? pw[i - 1] * 10 : 1;
	int n, m;
	cin >> n >> m;
	for(int i = 1, x; i <= n; i += 1){
		cin >> x;
		update(1, 1, n, i, x);
	}
	for(int i = 1, t; i <= m; i += 1){
		cin >> t;
		if(t == 2){
			int l, r;
			cin >> l >> r;
			cout << query(n, l, r) << "\n";
		}
		else{
			int j, x;
			cin >> j >> x;
			update(1, 1, n, j, x);
		}
	}
	return 0;
}