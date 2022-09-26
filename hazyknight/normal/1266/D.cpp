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

typedef long long ll;

const int MAXN = 300005;

int n,m,tot;

ll d[MAXN];
ll ans[MAXN][3];

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,w,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		d[u] -= w;
		d[v] += w;
	}
	for (int i = 1,j = 1;i <= n;)
	{
		if (d[i] <= 0)
		{
			i++;
			continue;
		}
		while (j <= n && d[j] >= 0)
			j++;
		ll v = min(d[i],-d[j]);
		tot++;
		ans[tot][0] = j;
		ans[tot][1] = i;
		ans[tot][2] = v;
		d[i] -= v;
		d[j] += v;
	}
	printf("%d\n",tot);
	for (int i = 1;i <= tot;i++)
		printf("%lld %lld %lld\n",ans[i][0],ans[i][1],ans[i][2]);
	return 0;
}