#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

const int MAXN = 100005;

int n;
int deg[MAXN];

int main()
{
	scanf("%d",&n);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		deg[u]++;
		deg[v]++;
	}
	for (int i = 1;i <= n;i++)
		if (deg[i] == 2)
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}