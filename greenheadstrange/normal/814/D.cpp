#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath> 
#include <algorithm>
#define maxn 1505
using namespace std;
const double pi = acos(-1.0);
struct edge
{
	long long u, v;
	edge *next;
}pool[maxn * 2], *h[maxn];
long long cnt = 0;
void addedge(long long u, long long v)
{
	edge *new1 = &pool[cnt++];
	new1->u = u, new1->v = v, new1->next = h[u], h[u] = new1;
}
struct circle
{
	long long x, y, r;
	double cov;
	bool operator < (const circle &a)const
	{
		return r < a.r;
	}
}c[maxn];
long long fa[maxn];
double dp[2][2][maxn];
bool bdp[2][2][maxn];
double gdp(long long t1, long long t2, long long a)
{
	if(bdp[t1][t2][a]) return dp[t1][t2][a];
	bdp[t1][t2][a] = 1;
	double ans[2] = {0, 0};
	double nw = c[a].cov;
	for(edge *p = h[a]; p; p = p->next)
		nw -= c[p->v].cov;
	ans[0] = (t1 ^ 1) * nw + t2 * nw;
	for(edge *p = h[a]; p; p = p->next)
		ans[0] += gdp(t1 ^ 1, t2, p->v);
	ans[1] = (t2 ^ 1) * nw + t1 * nw;
	for(edge *p = h[a]; p; p = p->next)
		ans[1] += gdp(t1, t2 ^ 1, p->v);
	dp[t1][t2][a] = max(ans[0], ans[1]);
	return dp[t1][t2][a];	
}
int main()
{
	long long n;
	scanf("%I64d", &n);
	for(long long i = 1; i <= n; i++)
		scanf("%I64d%I64d%I64d", &c[i].x, &c[i].y, &c[i].r), 
		c[i].cov = c[i].r * c[i].r * pi;
	sort(c + 1, c + n + 1);
	for(long long i = n; i >= 1; i--)
		for(long long j = i + 1; j <= n; j++)
		{
			double ndis = sqrt((c[i].x - c[j].x) * (c[i].x - c[j].x) + (c[i].y - c[j].y) * (c[i].y - c[j].y));
			if(ndis <= c[i].r + c[j].r - 0.000000001)
			{
				fa[i] = j;
				addedge(j, i);
				break;
			}
		}
	double ans = 0;
	for(long long i = 1; i <= n; i++)
		if(fa[i] == 0) ans += gdp(0, 0, i);
	printf("%.10lf\n", ans);
	return 0;
 }