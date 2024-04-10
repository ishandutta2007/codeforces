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

const int MAXN = 1000005;

int n,m,ans;

string s[MAXN];

vector<int> tag[2][MAXN];

void dfs(int x,int y,int v)
{
	if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#' || tag[v][x][y])
		return;
	tag[v][x][y] = 1;
	if (!v)
	{
		dfs(x + 1,y,v);
		dfs(x,y + 1,v);
	}
	else
	{
		dfs(x - 1,y,v);
		dfs(x,y - 1,v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> s[i];
		tag[0][i].resize(m);
		tag[1][i].resize(m);
	}
	dfs(0,0,0);
	dfs(n - 1,m - 1,1);
	if (!tag[1][0][0])
	{
		puts("0");
		return 0;
	}
	for (int i = 1;i < n + m - 2;i++)
	{
		int cnt = 0;
		for (int j = 0;j < n;j++)
			if (i - j >= 0 && i - j < m)
				cnt += (tag[0][j][i - j] && tag[1][j][i - j]);
		if (cnt == 1)
		{
			puts("1");
			return 0;
		}
	}
	puts("2");
	return 0;
}