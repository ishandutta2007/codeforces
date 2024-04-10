//Author: Heltion
//Date: 10-16-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 360000;
int a[maxn];
int mi[maxn << 4];
#define ls (v << 1)
#define rs ((v << 1) | 1)
#define tm ((tl + tr) >> 1)
void update(int v, int tl, int tr, int p, int x){
	if(tl == tr) mi[v] = x;
	else{
		if(p <= tm) update(ls, tl, tm, p, x);
		else update(rs, tm + 1, tr, p, x);
		mi[v] = min(mi[ls], mi[rs]);
	}
}
void build(int v, int tl, int tr){
	if(tl == tr) mi[v] = 1e9;
	else{
		build(ls, tl, tm);
		build(rs, tm + 1, tr);
		mi[v] = min(mi[ls], mi[rs]);
	}
}
int query(int v, int tl, int tr, int x){
	if(tl == tr) return tm;
	if(mi[ls] <= x) return query(ls, tl, tm, x);
	return query(rs, tm + 1, tr, x);
}
int dp[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		a[i + n] = a[i];
		a[i + n * 2] = a[i];
	}
	build(1, 1, 3 * n + 1);
	dp[3 * n + 1] = 3 * n + 1;
	int x = 1e9;
	update(1, 1, 3 * n + 1, 3 * n + 1, 0);
	for(int i = 3 * n; i; i -= 1){
		dp[i] = query(1, 1, 3 * n + 1, (a[i] - 1) / 2);
		x = min(dp[i] = min(x, dp[i]), x);
		update(1, 1, 3 * n + 1, i, a[i]);
	}
	if(dp[1] == 3 * n + 1) for(int i = 1; i <= n; i += 1) cout << "-1 ";
	else for(int i = 1; i <= n; i += 1) cout << dp[i] - i << " ";
	return 0;
}