#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

const int MAXN = 200005;

struct G
{
	long long x,y,vx,vy;
	long double vl;
}g[MAXN];

int n;

long long ans;

long double a,b,c;

long long val(long long x)
{
	return a * x + c;
}

long double dist(long double x,long double y)
{
	return (a * x + b * y + c) / sqrt(a * a + b * b);
}

bool cmp1(const G &a,const G &b)
{
	if (a.vx < b.vx)
		return a.vy < b.vy;
	return a.vx < b.vx;
}

bool cmp2(const G &a,const G &b)
{
	return a.vl < b.vl;
}

void calc()
{
	sort(g + 1,g + n + 1,cmp2);
	int j = 1;
	for (int i = 1;i <= n;i++)
	{
		if (i == n || g[i + 1].vl != g[i].vl)
		{
			long long cnt = i - j + 1;
			ans += cnt * (cnt - 1);
			sort(g + j,g + i + 1,cmp1);
			cnt = 0;
			for (int k = j;k <= i;k++)
			{
				cnt++;
				if (k == i || g[k].vx < g[k + 1].vx || g[k].vy < g[k + 1].vy)
				{
					ans -= cnt * (cnt - 1);
					cnt = 0;
				}
			}
			j = i + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	c = b,b = -1;
	for (int i = 1;i <= n;i++)
	{
		cin >> g[i].x >> g[i].vx >> g[i].vy;
		g[i].y = val(g[i].x);
		g[i].vl = dist(g[i].x + g[i].vx,g[i].y + g[i].vy);
	}
	calc();
	cout << ans << endl;
	return 0;
}