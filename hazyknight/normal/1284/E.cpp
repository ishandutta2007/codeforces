#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef double db;
typedef long long ll;

const int MAXN = 5005;
const db PI = acos(-1);

struct ARC
{
	db v;
	ll x,y;
	
	bool operator < (const ARC &p)const
	{
		if (fabs(v - p.v) > 1e-8)
			return v < p.v;
		return x * p.y - y * p.x >= 0;
	}
}arc[MAXN];

int n;
int x[MAXN];
int y[MAXN];

ll ans;

bool inhalf(ARC &a,ARC &b)
{
	if (fabs(a.v + PI - b.v) > 1e-8)
		return a.v + PI >= b.v;
	return a.x * b.y - a.y * b.x >= 0;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&x[i],&y[i]);
	ans = (ll)n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
	for (int i = 1;i <= n;i++)
	{
		int tot = 0;
		for (int j = 1;j <= n;j++)
			if (i != j)
			{
				arc[++tot].v = atan2(y[j] - y[i],x[j] - x[i]);
				arc[tot].x = x[j] - x[i];
				arc[tot].y = y[j] - y[i];
			}
		sort(arc + 1,arc + tot + 1);
		for (int j = tot + 1;j <= 2 * tot;j++)
		{
			arc[j] = arc[j - tot];
			arc[j].v += 2 * PI;
		}
		for (int j = 1,k = 1;j <= tot;j++)
		{
			while (k + 1 < j + tot && inhalf(arc[j],arc[k + 1]))
				k++;
			ans -= (ll)(k - j) * (k - j - 1) * (k - j - 2) / 6;
		}
	}
	printf("%lld\n",ans);
	return 0;
}