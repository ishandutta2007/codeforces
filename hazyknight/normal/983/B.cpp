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

const int MAXN = 5005;

int n,q;
int f[MAXN][MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&f[i][i]);
	for (int i = 2;i <= n;i++)
		for (int j = 1,k = i;k <= n;j++,k++)
			f[j][k] = f[j][k - 1] ^ f[j + 1][k];
	for (int i = 2;i <= n;i++)
		for (int j = 1,k = i;k <= n;j++,k++)
		{
			f[j][k] = max(f[j][k],f[j][k - 1]);
			f[j][k] = max(f[j][k],f[j + 1][k]);
		}
	scanf("%d",&q);
	for (int l,r,i = 1;i <= q;i++)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",f[l][r]);
	}
	return 0;
}