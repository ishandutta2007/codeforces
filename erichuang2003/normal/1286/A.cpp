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

int n;
int a[MAXN];
int f[MAXN][MAXN][2];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 0;i <= n;i++)
		for (int j = 0;j <= n;j++)
			f[i][j][0] = f[i][j][1] = 1e9;
	f[0][0][0] = f[0][0][1] = 0;
	for (int i = 0;i < n;i++)
		for (int j = 0;j <= i;j++)
		{
			if (!a[i + 1] || (a[i + 1] & 1))
				f[i + 1][j + 1][1] = min(f[i][j][0] + 1,f[i][j][1]);
			if (!a[i + 1] || (~a[i + 1] & 1))
				f[i + 1][j][0] = min(f[i][j][0],f[i][j][1] + 1);
		}
	printf("%d\n",min(f[n][(n + 1) / 2][0],f[n][(n + 1) / 2][1]));
	return 0;
}