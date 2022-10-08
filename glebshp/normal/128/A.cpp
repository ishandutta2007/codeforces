#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int size = 150;

bool used[size][size][size], vis[size][size][size];
char buf[size][size];

void dfs(int lv, int x, int y)
{
	if (lv > 100)
		return;
	int i, j;
	vis[lv][x][y] = true;
	for (i = -1; i < 2; i++)
		for (j = -1; j < 2; j++)
			if (x + i >= 0 && x + i < 8 && y + j >= 0 && y + j < 8 && !used[lv + 1][x + i][y + j] && !used[lv][x + i][y + j] && !vis[lv + 1][x + i][y + j])
				dfs(lv + 1, x + i, y + j);
}

int main()
{
	int i, j, k;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	for (i = 0; i < 8; i++)
		scanf("%s\n", buf[i]);
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			used[0][i][j] = (buf[i][j] == 'S');
	for (k = 1; k < 100; k++)
		for (i = 1; i < 8; i++)
			for (j = 0; j < 8; j++)
				used[k][i][j] = used[k - 1][i - 1][j];

	dfs(0, 7, 0);

	for (k = 0; k < 100; k++)
		if (vis[k][0][7])
		{
			printf("WIN\n");
			return 0;
		}
	printf("LOSE\n");	

    return 0;
}