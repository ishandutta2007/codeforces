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
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MAXN = 500005;

int T,n,m;

bool mark[MAXN];

vector<int> ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= 3 * n;i++)
			mark[i] = 0;
		ans.clear();
		for (int u,v,i = 1;i <= m;i++)
		{
			scanf("%d%d",&u,&v);
			if (!mark[u] && !mark[v])
			{
				ans.push_back(i);
				mark[u] = mark[v] = 1;
			}
		}
		if (ans.size() >= n)
		{
			puts("Matching");
			for (int i = 0;i < n;i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
		else
		{
			int N = n;
			puts("IndSet");
			for (int i = 1;i <= 3 * n && N;i++)
				if (!mark[i])
				{
					printf("%d ",i);
					N--;
				}
			printf("\n");
		}
	}
	return 0;
}