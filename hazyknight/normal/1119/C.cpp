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
#include <bitset>

using namespace std;

int n,m,b;
int a[505][505];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			scanf("%d",&a[i][j]);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			scanf("%d",&b);
			a[i][j] ^= b;
		}
	for (int i = 1;i < n;i++)
		for (int j = 1;j < m;j++)
			if (a[i][j])
			{
				a[i][j] ^= 1;
				a[i + 1][j] ^= 1;
				a[i][j + 1] ^= 1;
				a[i + 1][j + 1] ^= 1;
			}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (a[i][j])
			{
				puts("No");
				return 0;
			}
	puts("Yes");
	return 0;
}