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
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

const int MAXN = 1005;

struct Path
{
	int x,y,l;
}Q[10][MAXN * MAXN];

int n,m,p,CNT;
int l[10];
int ans[10];
int head[10];
int tail[10];

string s[MAXN];

vector<Path> mem;

void go(int id,int x,int y,int d)
{
	if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] != '.')
		return;
	CNT++;
	s[x][y] = char(id + '0');
	Q[id][++tail[id]] = (Path){x,y,d};
}

void bfs(int id)
{
	mem.clear();
	while (head[id] <= tail[id])
	{
		if (Q[id][head[id]].l == l[id])
		{
			mem.push_back(Q[id][head[id]]);
			head[id]++;
			continue;
		}
		int x = Q[id][head[id]].x,y = Q[id][head[id]].y,d = Q[id][head[id]].l;
		head[id]++;
		go(id,x - 1,y,d + 1);
		go(id,x,y - 1,d + 1);
		go(id,x + 1,y,d + 1);
		go(id,x,y + 1,d + 1);
	}
	head[id] = 1,tail[id] = 0;
	for (int i = 0;i < mem.size();i++)
	{
		mem[i].l = 0;
		Q[id][++tail[id]] = mem[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> p;
	for (int i = 1;i <= p;i++)
	{
		cin >> l[i];
		head[i] = 1;
		tail[i] = 0;
	}
	for (int i = 0;i < n;i++)
	{
		cin >> s[i];
		for (int j = 0;j < m;j++)
			if (s[i][j] != '.' && s[i][j] != '#')
				Q[s[i][j] - '0'][++tail[s[i][j] - '0']] = (Path){i,j,0};
	}
	CNT = 1;
	while (CNT)
	{
		CNT = 0;
		for (int i = 1;i <= p;i++)
			bfs(i);
	}
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			if (s[i][j] != '#' && s[i][j] != '.')
				ans[s[i][j] - '0']++;
	for (int i = 1;i <= p;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}