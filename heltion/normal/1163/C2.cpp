//Author: Heltion
//Date: 2019-05-09
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 1200;
struct vec{
	LL x, y;
	vec operator - (const vec &o){
		return (vec){x - o.x, y - o.y};
	}
}p[maxn];
LL cross(const vec &a, const vec &b){
	return a.x * b.y - a.y * b.x;
}
struct line{
	vec A, B;
	void init(){
		if(B.y < A.y) swap(A, B);
		if(A.y == B.y and B.x < A.x) swap(A, B);
		B = B - A;
	}
	bool operator < (const line &o){
		LL cr = cross(B, o.B);
		if(cr != 0) return cr > 0;
		return cross(A - o.A, B) < 0;
	}
}e[maxn * maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> p[i].x >> p[i].y;
	int tot = 0;
	for(int i = 0; i < n; i += 1)
		for(int j = i + 1; j < n; j += 1){
			e[tot].A = p[i];
			e[tot].B = p[j];
			e[tot].init();
			tot += 1;
		}
	sort(e, e + tot);
	LL ans = 0, sum = 0;
	for(int i = 0, j, k, c; i < tot; i = j){
		j = i;
		while(j < tot and cross(e[j].B, e[i].B) == 0) j += 1;
		c = 0;
		for(k = i; k < j; k += 1)
			if(k == i or cross(e[k].A - e[k - 1].A, e[i].B) != 0) c += 1;
		ans += sum * c;
		sum += c;
	}
	cout << ans;
	return 0;
}