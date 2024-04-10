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

const int MAXN = 100005;

int n,tot;
int p[MAXN];

bool vis[MAXN];

int main()
{
	scanf("%d",&n);
	if (n <= 2)
	{
		printf("1\n");
		for (int i = 1;i <= n;i++)
			printf("1 ");
		printf("\n");
		return 0;
	}
	printf("2\n");
	for (int i = 2;i <= n + 1;i++)
	{
		if (!vis[i])
			p[++tot] = i;
		printf("%d ",vis[i] + 1);
		for (int j = 1;j <= tot && i * p[j] <= n + 1;j++)
		{
			vis[i * p[j]] = 1;
			if (i % p[j] == 0)
				break;
		}
	}
	printf("\n");
	return 0;
}