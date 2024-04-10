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

const int MAXN = 105;

int n;
int x[MAXN];
int y[MAXN];
int fa[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		fa[i] = i;
		scanf("%d%d",&x[i],&y[i]);
	}
	int ans = n - 1;
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			if ((x[i] == x[j] || y[i] == y[j]) && getroot(i) != getroot(j))
			{
				fa[getroot(i)] = getroot(j);
				ans--;
			}
	printf("%d\n",ans);
	return 0;
}