//Author: Heltion
//Date: 09-19-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 540000;
struct P{
	int x, y, c;
}p[maxn];
int dx[maxn << 1], xn;
LL sum[maxn << 3], psum[maxn << 3];
int xb[maxn << 3];
vector<int> G[maxn << 1];
#define ls (v << 1)
#define rs ((v << 1) | 1)
#define tm ((tl + tr) >> 1)
void add(int v, int tl, int tr, int p, LL x){
	if(tl == tr){
		sum[v] += x;
		if(sum[v] >= 0){
			xb[v] = tm + 1;
			psum[v] = sum[v];
		}
		else{
			xb[v] = tm;
			psum[v] = 0;
		}
	}
	else{
		if(p <= tm) add(ls, tl, tm, p, x);
		else add(rs, tm + 1, tr, p, x);
		sum[v] = sum[ls] + sum[rs];
		if(psum[ls] <= sum[ls] + psum[rs]){
			xb[v] = xb[rs];
			psum[v] = sum[ls] + psum[rs];
		}
		else{
			xb[v] = xb[ls];
			psum[v] = psum[ls];
		}
	}
}
pair<int, LL> query(int v, int tl, int tr, int R){
	if(tr <= R) return {xb[v], psum[v]};
	if(R <= tm) return query(ls, tl, tm, R);
	auto q = query(rs, tm + 1, tr, R);
	if(psum[ls] <= sum[ls] + q.second) return {q.first, sum[ls] + q.second};
	return {xb[ls], psum[ls]};
}
LL gp(int v, int tl, int tr, int x){
	if(tl == tr) return sum[v];
	if(x <= tm) return gp(ls, tl, tm, x);
	return gp(rs, tm + 1, tr, x);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		cin >> p[i].x >> p[i].y >> p[i].c;
		if(p[i].x >= p[i].y) swap(p[i].x, p[i].y);
		dx[xn ++] = p[i].x;
		dx[xn ++] = p[i].y;
	}
	sort(dx, dx + xn);
	xn = unique(dx, dx + xn) - dx;
	for(int i = 0; i < n; i += 1){
		int y = lower_bound(dx, dx + xn, p[i].y) - dx;
		G[y].push_back(i);
	}
	dx[xn] = 2e9;
	LL pans = 0, ans = 0, L = xn, R = xn;
	for(int i = 0; i < xn; i += 1) {
		for(int j : G[i]){
			pans += p[j].c;
			int x = lower_bound(dx, dx + xn, p[j].x) - dx;
			add(1, 0, xn - 1, x, -p[j].c);
		}
		auto p = query(1, 0, xn - 1, i);
		if(pans - dx[i] + p.second + dx[0] > ans){
			ans = pans - dx[i] + p.second + dx[0];
			R = i;
			L = p.first;
		}
		add(1, 0, xn - 1, i, dx[i + 1] - dx[i]);
		//cout << i << " " << p.first << " " << p.second << "\n";
		//for(int j = 0; j <= i; j += 1)  cout << j << " " << gp(1, 0, xn - 1, j) << "\n";
	}
	cout << ans << "\n";
	cout << dx[L] << " " << dx[L] << " " << dx[R] << " " << dx[R] << "\n";
	return 0;
}