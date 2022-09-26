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

const int MAXN = 100005;

int T,n;
int a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		int MX = -1e9 - 1,MAX = 0;
		for (int i = 1;i <= n;i++)
			if (a[i] < MX)
				MAX = max(MAX,MX - a[i]);
			else
				MX = a[i];
		bool ok = 0;
		for (int i = 30;i >= 0;i--)
			if (MAX >= (1 << i))
			{
				ok = 1;
				printf("%d\n",i + 1);
				break;
			}
		if (!ok)
			puts("0");
	}
	return 0;
}