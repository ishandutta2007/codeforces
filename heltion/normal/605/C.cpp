#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000; 
struct vec{
	LL x, y;
}p[maxn], st[maxn];
inline LL cross(const vec &a, const vec &b){
	return a.x * b.y - a.y * b.x;
}
vec operator - (const vec &a, const vec &b){
	return (vec){a.x - b.x, a.y - b.y};
}
bool operator < (const vec &a, const vec&b){
	return cross(a, b) > 0;
}
int main(){
	int n, X, Y;
	scanf("%d %d %d", &n, &X, &Y);
	for(int i = 1; i <= n; i += 1){
		scanf("%lld %lld", &p[i].x, &p[i].y);
		p[0].x = max(p[0].x, p[i].x);
		p[n + 1].y = max(p[n + 1].y, p[i].y);
	}
	sort(p, p + n + 2);
	int m = 0;
	for(int i = 0; i <= n + 1; i += 1){
		while(m >= 2 and cross(p[i] - st[m - 1], st[m] - st[m - 1]) >= 0) m -= 1;
		st[m += 1] = p[i];
	}
	//for(int i = 1; i <= m; i += 1) printf("(%lld, %lld)\n", st[i].x, st[i].y);
	for(int i = 1; i < m; i += 1){
		LL y = -cross(st[i], (vec){X, Y}), x = cross(st[i + 1] - st[i],(vec){X, Y});
		if(x < 0) x = -x, y = -y;
		if(y <= x and y >= 0){
			y = cross(st[i], st[i + 1] - st[i]), x = cross((vec){X, Y}, st[i + 1] - st[i]);
			printf("%.15lf", 1.0 * x / y);
			return 0;
		}
	}
}