//Author: Heltion
//Date: 2019-05-14
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr LL maxn = 540000;
constexpr LL mod = 1e9+7;
LL a[maxn];
LL added[maxn << 2], ssum[maxn << 2];
LL added2[maxn << 2], ssum2[maxn << 2];
#define ls (v << 1)
#define rs (v << 1 | 1)
#define tm ((tl + tr) >> 1)
void add(LL v, LL tl, LL tr, LL x){
	added[v] += x;
	ssum[v] += x * (tr - tl + 1);
}
void push_down(LL v, LL tl, LL tr){
	add(ls, tl, tm, added[v]);
	add(rs, tm + 1, tr, added[v]);
	added[v] = 0;
}
void add(LL v, LL tl, LL tr, LL L, LL R, LL x){
	if(tl >= L and tr <= R) add(v, tl, tr, x);
	else{
		push_down(v, tl, tr);
		if(R > tm) add(rs, tm + 1, tr, L, R, x);
		if(L <= tm) add(ls, tl, tm, L, R, x);
		ssum[v] = ssum[ls] + ssum[rs];
	}
}
LL sum(LL v, LL tl, LL tr, LL L, LL R){
	if(tl >= L and tr <= R) return ssum[v];
	LL res = 0;
	push_down(v, tl, tr);
	if(R > tm) res += sum(rs, tm + 1, tr, L, R);
	if(L <= tm) res += sum(ls, tl, tm, L, R);
	return res;
}
void add2(LL v, LL tl, LL tr, LL x){
	added2[v] += x;
	ssum2[v] += x * (tr - tl + 1);
}
void push_down2(LL v, LL tl, LL tr){
	add2(ls, tl, tm, added2[v]);
	add2(rs, tm + 1, tr, added2[v]);
	added2[v] = 0;
}
void add2(LL v, LL tl, LL tr, LL L, LL R, LL x){
	if(tl >= L and tr <= R) add2(v, tl, tr, x);
	else{
		push_down2(v, tl, tr);
		if(R > tm) add2(rs, tm + 1, tr, L, R, x);
		if(L <= tm) add2(ls, tl, tm, L, R, x);
		ssum2[v] = ssum2[ls] + ssum2[rs];
	}
}
LL sum2(LL v, LL tl, LL tr, LL L, LL R){
	if(tl >= L and tr <= R) return ssum2[v];
	LL res = 0;
	push_down2(v, tl, tr);
	if(R > tm) res += sum2(rs, tm + 1, tr, L, R);
	if(L <= tm) res += sum2(ls, tl, tm, L, R);
	return res;
}
vector<pair<LL, LL>> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n;
	cin >> n;
	for(LL i = 1; i <= n; i += 1){
		cin >> a[i];
		v.push_back({a[i], i});
	}
	sort(v.begin(), v.end());
	LL res = 0;
	add(1, 1, n, 1, n, 1);
	add2(1, 1, n, 1, n, 1);
	for(auto p : v){
		LL x1 = sum(1, 1, n, p.second, p.second);
		LL x2 = sum2(1, 1, n, p.second, p.second);
		LL y = (sum(1, 1, n, 1, p.second) - (x1 - 1) * p.second) % mod;
		LL z = (sum2(1, 1, n, p.second, n) - (x2 - 1) * (n - p.second + 1)) % mod;
		res += p.first * ((y * (n - p.second + 1) + z * p.second - (n - p.second + 1) * p.second) % mod + mod) % mod;
		//cout << x1 << " " << x2 << " " << y << " " << z << endl;
		res %= mod;
		add(1, 1, n, 1, p.second, 1);
		add2(1, 1, n, p.second, n, 1);
	}
	cout << res;
	return 0;
}
//5 2 4 7
//1 1 1 1
//2 2 1 1
//3 3 2 1 
//4 3 2 1