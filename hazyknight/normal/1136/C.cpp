#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAXN = 505;

int n,m,tota,totb;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int vala[MAXN];
int valb[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			scanf("%d",&a[i][j]);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			scanf("%d",&b[i][j]);
	for (int i = 1;i <= n + m;i++)
	{
		tota = totb = 0;
		for (int j = 1;j < i;j++)
			if (j <= n && i - j >= 1 && i - j <= m)
				vala[++tota] = a[j][i - j];
		for (int j = 1;j < i;j++)
			if (j <= n && i - j >= 1 && i - j <= m)
				valb[++totb] = b[j][i - j];
		sort(vala + 1,vala + tota + 1);
		sort(valb + 1,valb + totb + 1);
		for (int j = 1;j <= tota;j++)
			if (vala[j] != valb[j])
			{
				puts("NO");
				return 0;
			}
	}
	puts("YES");
	return 0;
}