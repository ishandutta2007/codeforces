#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 20;
double PI = acos(-1);
double dp[1 << maxn], l, r;
bool vis[1 << maxn];
int a[maxn], n;
struct vec{
	double x, y;
	vec operator - (const vec&b){
		return (vec){x - b.x, y - b.y};
	}
}p[maxn];
vec rotate(const vec &v, const double &a){
	return (vec){v.x * cos(a) - v.y * sin(a), v.x * sin(a) + v.y * cos(a)};
}
double solve(int mask){
	if(vis[mask]) return dp[mask];
	vis[mask] = 1;
	dp[mask] = l;
	for(int i = 0; i < n; i += 1)
		if((1 << i) & mask){
			double pl = solve((1 << i) ^ mask);
			vec v = (vec){pl, 0} - p[i];
			v = rotate(v, PI * a[i] / 180);
			if(v.y >= 0) dp[mask] = r;
			else dp[mask] = max(dp[mask], p[i].x - p[i].y / v.y * v.x);
		}
	return min(r, dp[mask]);
}
int main(){
	scanf("%d %lf %lf", &n, &l, &r);
	for(int i = 0; i < n; i += 1) scanf("%lf %lf %d", &p[i].x, &p[i].y, a + i);
	vis[0] = true;
	dp[0] = l;
	printf("%.9lf", solve((1 << n) - 1) - l);
}