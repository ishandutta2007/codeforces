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

const int MAXN = 400005;

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
		int g = 0,s = 0,b = 0;
		for (int i = 1;i < n;i++)
			if (a[i] != a[i + 1])
			{
				g = i;
				break;
			}
		for (int i = 2 * g + 1;i < n;i++)
			if (a[i] != a[i + 1])
			{
				s = i - g;
				break;
			}
		for (int i = n / 2;i > g + s;i--)
			if (a[i] != a[i + 1])
			{
				b = i - g - s;
				break;
			}
		if (!g || !b || !s || g >= b || g >= s)
			printf("0 0 0\n");
		else
			printf("%d %d %d\n",g,s,b);	
	}
	return 0;
}