#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

const int MAXN = 12;
const int MAXM = 2005;

int T,n,m;
int a[MAXM][MAXN];
int f[MAXM][1 << MAXN];

bool mark[MAXM];

pair<int,int> b[MAXM];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		memset(mark,0,sizeof(mark));
		for (int i = 0;i < n;i++)
			for (int j = 1;j <= m;j++)
				scanf("%d",&a[j][i]);
		for (int i = 1;i <= m;i++)
		{
			int MAX = 0;
			for (int j = 0;j < n;j++)
				MAX = max(MAX,a[i][j]);
			b[i] = make_pair(-MAX,i);
		}
		nth_element(b + 1,b + min(n,m),b + m + 1);
		for (int j = 1;j <= min(n,m);j++)
			mark[b[j].second] = 1;
		int lst = 0;
		for (int i = 1;i <= m;i++)
		{
			if (!mark[i])
				continue;
			for (int j = 0;j < (1 << n);j++)
				f[i][j] = 0;
			for (int o = 0;o < n;o++)
			{
				for (int j = 0;j < (1 << n);j++)
				{
					int S = (1 << n) - 1,T = 0,sum = 0;
					for (int k = 0;k < n;k++)
						if (j >> k & 1)
						{
							T ^= 1 << ((k + o) % n);
							S ^= 1 << ((k + o) % n);
							sum += a[i][k];
						}
					for (int k = S;;k = (k - 1) & S)
					{
						f[i][k | T] = max(f[i][k | T],f[lst][k] + sum);
						if (!k)
							break;
					}
				}
			}
			lst = i;
		}
		printf("%d\n",f[lst][(1 << n) - 1]);
	}
	return 0;
}