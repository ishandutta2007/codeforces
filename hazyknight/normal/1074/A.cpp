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
#include <iomanip>

using namespace std;

const int MAXN = 100005;

int n,m,ans;
int a[MAXN];
int b[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	for (int x,y,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&x,&b[i],&y);
		if (x != 1)
		{
			i--;
			m--;
			continue;
		}
	}
	ans = n + m;
	sort(b + 1,b + m + 1);
	int j = 1;
	a[n + 1] = 1000000000;
	for (int i = 0;i <= n;i++)
	{
		while (j <= m && b[j] < a[i + 1])
			j++;
		ans = min(ans,i + m - j + 1);
	}
	printf("%d\n",ans);
	return 0;
}