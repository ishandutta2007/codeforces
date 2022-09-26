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

const int MAXN = 200005;

int T,n,x,a,y,b;

ll k;
ll p[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%lld",&p[i]);
			p[i] /= 100;
		}
		sort(p + 1,p + n + 1);
		reverse(p + 1,p + n + 1);
		for (int i = 1;i <= n;i++)
			p[i] += p[i - 1];
		scanf("%d%d%d%d%lld",&x,&a,&y,&b,&k);
		if (x < y)
		{
			swap(x,y);
			swap(a,b);
		}
		ll X = 0,Y = 0,XY = 0;
		bool ok = 0;
		for (int i = 1;i <= n;i++)
		{
			if (i % a == 0 && i % b == 0)
				XY++;
			else if (i % a == 0)
				X++;
			else if (i % b == 0)
				Y++;
			if ((x + y) * p[XY] + x * (p[XY + X] - p[XY]) + y * (p[XY + X + Y] - p[XY + X]) >= k)
			{
				printf("%d\n",i);
				ok = 1;
				break;
			}
		}
		if (!ok)
			puts("-1");
	}
	return 0;
}