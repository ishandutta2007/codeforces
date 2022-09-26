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
 
#define TIME (double)clock()/CLOCKS_PER_SEC
 
using namespace std;
 
const int MAXN = 100005;
 
int n,tot;
int ans[MAXN];
 
pair<int,int> a[MAXN];
pair<int,int> b[MAXN];
 
int main()
{
	srand(20030506);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a + 1,a + n + 1);
	b[1] = a[1];
	b[2] = a[2];
	tot = 2;
	for (int i = 3;i <= n;i++)
	{
		if (a[i].first != a[i - 2].first)
			b[++tot] = a[i];
		else
			ans[a[i].second] = 1;
	}
	for (int i = 1;i <= tot;i++)
		a[i] = b[i];
	while (TIME <= 0.4)
	{
		random_shuffle(a + 1,a + tot + 1);
		int g = 0;
		for (int i = 1;i <= tot;i++)
		{
			g = __gcd(g,a[i].first);
			if (g == 1)
			{
				g = 0;
				for (int j = i + 1;j <= tot;j++)
					g = __gcd(g,a[j].first);
				if (g == 1)
				{
					for (int j = 1;j <= i;j++)
						ans[a[j].second] = 1;
					for (int j = i + 1;j <= tot;j++)
						ans[a[j].second] = 2;
					puts("YES");
					for (int j = 1;j <= n;j++)
						printf("%d ",ans[j]);
					printf("\n");
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}