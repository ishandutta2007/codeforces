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

const int MAXN = 300005;

int T,n;
int a[MAXN];
int st[MAXN];
int ed[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			st[i] = ed[i] = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			if (!st[a[i]])
				st[a[i]] = i;
			ed[a[i]] = i;
		}
		int lst = 0,cnt = 0,MAX = 0,sum = 0;
		for (int i = 1;i <= n;i++)
		{
			if (!st[i])
				continue;
			sum++;
			if (!lst || st[i] < ed[lst])
				cnt = 1;
			else
				cnt++;
			lst = i;
			MAX = max(MAX,cnt);
		}
		printf("%d\n",sum - MAX);
	}
	return 0;
}