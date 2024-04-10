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

int n,m,b,g,MAX,MAX2,MIN = 2e9;

long long ans;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&b);
		ans += b;
		if (b >= MAX)
		{
			MAX2 = MAX;
			MAX = b;
		}
		else if (b > MAX2)
			MAX2 = b;
	}
	ans *= m;
	for (int i = 1;i <= m;i++)
	{
		scanf("%d",&g);
		if (MAX > g)
		{
			puts("-1");
			return 0;
		}
		if (MAX == g)
			MIN = 0;
		MIN = min(MIN,g - MAX2 - (g - MAX));
		ans += g - MAX;
	}
	printf("%lld\n",ans + MIN);
	return 0;
}