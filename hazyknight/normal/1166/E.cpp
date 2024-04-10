#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

int n,m,k,a;

bitset<10001> low[55];
bitset<10001> high[55];

int main()
{
	scanf("%d%d",&m,&n);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d",&k);
		for (int j = 1;j <= k;j++)
		{
			scanf("%d",&a);
			high[i][a] = 1;
		}
		for (int j = 1;j <= n;j++)
			if (!high[i][j])
				low[i][j] = 1;
	}
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= m;j++)
			if ((high[i] | low[j]) == low[j])
			{
				puts("impossible");
				return 0;
			}
	puts("possible");
	return 0;
}