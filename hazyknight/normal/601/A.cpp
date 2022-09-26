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

const int MAXN = 405;
const int INF = (1 << 30) - 1;

int n,m;
int G[MAXN][MAXN];

int main()
{
	cin >> n >> m;
	for (int u,v,i = 1;i <= m;i++)
	{
		cin >> u >> v;
		G[u][v] = G[v][u] = 1;
	}
	if (G[1][n])
	{
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				if (i != j)
				{
					if (G[i][j])
						G[i][j] = INF;
					else
						G[i][j] = 1;
				}
	}
	else
	{
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				if (i != j && !G[i][j])
					G[i][j] = INF;
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
	cout << (G[1][n] == INF ? -1 : G[1][n]) << endl;
	return 0;
}