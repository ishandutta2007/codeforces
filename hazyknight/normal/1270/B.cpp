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

int T,n;
int a[200005];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		bool ok = 0;
		for (int i = 1;i < n;i++)
			if (abs(a[i] - a[i + 1]) > 1)
			{
				puts("YES");
				ok = 1;
				printf("%d %d\n",i,i + 1);
				break;
			}
		if (!ok)
			puts("NO");
	}
	return 0;
}