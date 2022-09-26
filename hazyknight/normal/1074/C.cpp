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
#include <iomanip>

using namespace std;

const int MAXN = 300005;

int n,ans;
int M[4];
int x[MAXN];
int y[MAXN];

int dist(int i,int j)
{
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if (!M[0] || x[i] < x[M[0]])
			M[0] = i;
		if (!M[1] || y[i] < y[M[1]])
			M[1] = i;
		if (!M[2] || x[i] > x[M[2]])
			M[2] = i;
		if (!M[3] || y[i] > y[M[3]])
			M[3] = i;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < 4;j++)
			for (int k = j + 1;k < 4;k++)
				if (i != M[j] && i != M[k])
					ans = max(ans,dist(M[j],M[k]) + dist(M[k],i) + dist(i,M[j]));
	printf("%d ",ans);
	ans = dist(M[0],M[1]) + dist(M[1],M[2]) + dist(M[2],M[3]) + dist(M[3],M[0]);
	for (int i = 4;i <= n;i++)
		printf("%d ",ans);
	printf("\n");
	return 0;
}