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

const int MAXN = 200005;

int n,m,ans;
int fa[MAXN];

bool exist[MAXN];

int getroot(int u)
{
	return fa[u] == u ? u : fa[u] = getroot(fa[u]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		fa[i] = i;
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		if (getroot(u) != getroot(v))
			fa[getroot(u)] = getroot(v);
	}
	for (int i = 1;i <= n;i++)
		exist[getroot(i)] = 1;
	for (int i = 1;i <= n;i++)
		ans += exist[i];
	printf("%d\n",ans + m - n);
	return 0;
}