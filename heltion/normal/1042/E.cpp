#include<bits/stdc++.h>
#define maxn 1200000
using namespace std;
typedef long long LL;
const LL P = 998244353;
struct node{
	LL x, y, k;
	bool operator < (const node &rhs){
		return k < rhs.k;
	}
}p[maxn];
LL xfh[maxn], yfh[maxn], xh[maxn], yh[maxn], sum[maxn], ans[maxn];
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % P)
		if(r & 1) res = res * a % P;
	return res;
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1){
			scanf("%lld", &p[i * m + j].k);
			p[i * m + j].x = i;
			p[i * m + j].y = j;
		}
	sort(p, p + n * m);
	int q = 0;
	xfh[0] = p[0].x * p[0].x % P;
	yfh[0] = p[0].y * p[0].y % P;
	xh[0] = p[0].x;
	yh[0] = p[0].y;
	for(int i = 1; i < n * m; i += 1){
		xfh[i] = (xfh[i - 1] + p[i].x * p[i].x % P) % P;
		yfh[i] = (yfh[i - 1] + p[i].y * p[i].y % P) % P;
		xh[i] = (xh[i - 1] + p[i].x) % P;
		yh[i] = (yh[i - 1] + p[i].y) % P;
		//printf("%d %d\n", i, q);
		//printf("xfh[%d] = %lld\n", i, xfh[i]);
		//printf("xh[%d] = %lld\n", i, xh[i]);
		//printf("yfh[%d] = %lld\n", i, yfh[i]);
		//printf("yh[%d] = %lld\n", i, yh[i]);
		ans[i] = sum[q] + (xfh[q] + yfh[q] + p[i].x * p[i].x % P * (q + 1) % P + p[i].y * p[i].y % P * (q + 1) % P + xh[q] * p[i].x % P * (P - 2) % P + yh[q] * p[i].y % P * (P - 2) % P) % P;
		ans[i] = ans[i] * power(q + 1, P - 2) % P;
		if(p[q].k == p[i].k) ans[i] = 0;
		sum[i] = (ans[i] + sum[i - 1]) % P;
		//printf("ans[%d] = %lld\n", i, ans[i]);
		if(i + 1 < n * m && p[i].k != p[i + 1].k) q = i;
	}
	LL r, c;
	scanf("%lld %lld", &r, &c);
	for(int i = 0; i < n * m; i += 1)
		if(p[i].x == r - 1 && p[i].y == c - 1)
			printf("%lld\n", ans[i]);
}