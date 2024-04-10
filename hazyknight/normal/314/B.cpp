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

const int MAXN = 105;

int b,d,n,m,pos,ans;
int to[MAXN];
int cnt[MAXN];

char a[MAXN];
char c[MAXN];

int main()
{
	scanf("%d%d%s%s",&b,&d,a + 1,c + 1);
	n = strlen(a + 1);
	m = strlen(c + 1);
	for (int i = 1;i <= m;i++)
	{
		to[i] = i;
		for (int j = 1;j <= n;j++)
			if (a[j] == c[to[i]])
			{
				if (to[i] == m)
				{
					cnt[i]++;
					to[i] = 1;
				}
				else
					to[i]++;
			}
	}
	pos = 1;
	for (int i = 1;i <= b;i++)
	{
		ans += cnt[pos];
		pos = to[pos];
	}
	printf("%d\n",ans / d);
	return 0;
}