#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1005;
const int MAXM = 10005;

struct Event
{
	int t,p;
	
	bool operator < (const Event &a) const
	{
		return t > a.t;
	}
};

int n,m,g,r;
int d[MAXM];
int f[MAXN][MAXM];

priority_queue<Event> Q;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++)
		scanf("%d",&d[i]);
	sort(d + 1,d + m + 1);
	scanf("%d%d",&g,&r);
	for (int i = 1;i <= m;i++)
		for (int j = 0;j <= g;j++)
			f[j][i] = 1e9;
	Q.push((Event){0,1});
	while (!Q.empty())
	{
		int t = Q.top().t,p = Q.top().p,u = t % (g + r);
		Q.pop();
		if (f[u][p] < t)
			continue;
		if (p == m)
		{
			printf("%d\n",t);
			return 0;
		}
		if (u == g)
		{
			u = 0;
			t += r;
		}
		int len = d[p] - d[p - 1];
		if (p > 1 && len <= g - u && f[len + u][p - 1] > t + len)
		{
			f[len + u][p - 1] = t + len;
			Q.push((Event){t + len,p - 1});
		}
		len = d[p + 1] - d[p];
		if (p < m && len <= g - u && f[len + u][p + 1] > t + len)
		{
			f[len + u][p + 1] = t + len;
			Q.push((Event){t + len,p + 1});
		}
	}
	puts("-1");
	return 0;
}