#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define maxn 200005
using namespace std;
const double INF = 999999999999999.0;
int T;
int n;
double a[maxn], sum, sum1;
void solve()
{
	scanf("%d", &n);
	sum = sum1 = 0.0;
	for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
	}
	double ans = -INF;
	double res1 = 0.0, res2 = 0.0;
	for (int i = 1; i <= n; i++)
	{
		res1 += a[n - i + 1];
		res2 += a[i];
		double x = i;
		ans = max(ans, ((n - 2 * x) * res1 + sum * x) / x / (n - x));
		ans = max(ans, ((n - 2 * x) * res2 + sum * x) / x / (n - x));
	}
	printf("%.8f\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}