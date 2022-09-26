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
 
typedef double db;
 
const int MAXN = 85;
 
int n,tot;
int L[MAXN];
int R[MAXN];
int val[MAXN << 1];
 
db add[MAXN];
db ans[MAXN][MAXN];
db f[2][MAXN][MAXN];
 
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&L[i],&R[i]);
		val[++tot] = L[i];
		val[++tot] = R[i];
	}
	sort(val + 1,val + tot + 1);
	tot = unique(val + 1,val + tot + 1) - val - 1;
	for (int i = 1;i < tot;i++)
	{
		for (int cur = 1;cur <= n;cur++)
		{
			if (L[cur] >= val[i + 1] || R[cur] <= val[i])
				continue;
			swap(L[cur],L[n]);
			swap(R[cur],R[n]);
			n--;
			memset(f,0,sizeof(f));
			f[0][0][0] = 1;
			for (int j = 1;j <= n;j++)
			{
				db t = 1. / (R[j] - L[j]);
				if (R[j] <= val[i])
				{
					for (int k = 0;k <= j;k++)
						for (int l = 0;k + l <= j;l++)
							f[j & 1][k][l] = (k ? f[~j & 1][k - 1][l] : 0);
				}
				else if (L[j] >= val[i + 1])
				{
					for (int k = 0;k <= j;k++)
						for (int l = 0;k + l <= j;l++)
							f[j & 1][k][l] = f[~j & 1][k][l];
				}
				else
				{
					for (int k = 0;k <= j;k++)
						for (int l = 0;k + l <= j;l++)
						{
							f[~j & 1][k][l] *= t;
							f[j & 1][k][l] = f[~j & 1][k][l] * (R[j] - val[i + 1]) + (k ? f[~j & 1][k - 1][l] * (val[i] - L[j]) : 0) + (l ? f[~j & 1][k][l - 1] * (val[i + 1] - val[i]) : 0);
						}
				}
			}
			memset(add,0,sizeof(add));
			for (int j = 0;j <= n;j++)
				for (int k = 0;j + k <= n;k++)
				{
					db t = f[n & 1][j][k] * (val[i + 1] - val[i]) / (R[n + 1] - L[n + 1]) / (k + 1);
					add[j + 1] += t;
					add[j + k + 2] -= t;
				}
			n++;
			db sum = 0;
			for (int j = 1;j <= n;j++)
			{
			    sum += add[j];
			    ans[cur][j] += sum;
			}
			swap(L[cur],L[n]);
			swap(R[cur],R[n]);
		}
	}
	for (int i = 1;i <= n;i++,printf("\n"))
		for (int j = 1;j <= n;j++)
			printf("%.6lf ",(double)ans[i][j]);
	return 0;
}