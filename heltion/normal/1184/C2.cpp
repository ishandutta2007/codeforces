//Author: Heltion
//Date: 07-31-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 320000;
pair<int, int> p[maxn];
int y[maxn];
int L[maxn];
int ma[maxn], added[maxn];
#define ls (v << 1)
#define rs ((v << 1) | 1)
#define tm ((tl + tr) >> 1)
void add(int v, int x){
	added[v] += x;
	ma[v] += x;
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
		ma[v] = max(ma[ls], ma[rs]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, r, yn;
	cin >> n >> r;
	for(int i = 1; i <= n; i += 1){
		int x, y;
		cin >> x >> y;
		p[i].first = y + x;
		p[i].second = y - x;
	}
	for(int i = 1; i <= n; i += 1) y[i] = p[i].second;
	sort(y + 1, y + n + 1);
	yn = unique(y + 1, y + n + 1) - y - 1;
	for(int i = 1, j = 1; i <= n; i += 1){
		while(y[i] - y[j] > 2 * r) j += 1;
		L[i] = j;
	}
	sort(p + 1, p + n + 1);
	int ans = 0;
	for(int i = 1, j = 1; i <= n; i += 1){
		int R = lower_bound(y + 1, y + yn + 1, p[i].second) - y;
		add(1, 1, yn, L[R], R, 1);
		while(p[i].first - p[j].first > 2 * r){
			int R = lower_bound(y + 1, y + yn + 1, p[j].second) - y;
			add(1, 1, yn, L[R], R, -1);
			j += 1;
		}
		ans = max(ans, ma[1]);
	}
	cout << ans;
	return 0;
}