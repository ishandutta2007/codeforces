#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 100005;

int T,n;
int a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int tot = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			tot ^= a[i];
		}
		if (!tot)
		{
			puts("DRAW");
			continue;
		}
		int t = 0;
		for (int i = 30;i >= 0;i--)
			if (tot >> i & 1)
			{
				t = i;
				break;
			}
		int one = 0;
		for (int i = 1;i <= n;i++)
			one += (a[i] >> t & 1);
		int zero = n - one;
		if (one % 4 == 1)
			puts("WIN");
		else
		{
			if (zero % 2 == 0)
				puts("LOSE");
			else
				puts("WIN");
		}
	}
	return 0;
}