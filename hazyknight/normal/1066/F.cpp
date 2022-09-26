#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector> 
#include <map>
#include <iomanip>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

struct Coord
{
	int x,y;
	Coord(int X = 0,int Y = 0)
	{
		x = X;
		y = Y;
	}
	
	int level()
	{
		return max(x,y);
	}
	
	int dist(Coord p)
	{
		return abs(x - p.x) + abs(y - p.y);
	}
	
	bool operator < (const Coord &p)const
	{
		return max(x,y) < max(p.x,p.y);
	}
}c[MAXN],st[MAXN][2];

int n,cur,id;
int len[MAXN];

ll f[MAXN][2];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&c[i].x,&c[i].y);
	sort(c + 1,c + n + 1);
	for (int i = 1;i <= n;i++)
	{
		if (c[i].level() != c[i - 1].level())
		{
			len[id] = st[id][0].dist(st[id][1]);
			id++;
			cur = c[i].level();
			st[id][0] = st[id][1] = c[i];
		}
		else
		{
			if (c[i].dist(Coord(cur,0)) > st[id][0].dist(Coord(cur,0)))
				st[id][0] = c[i];
			if (c[i].dist(Coord(0,cur)) > st[id][1].dist(Coord(0,cur)))
				st[id][1] = c[i];
		}
	}
	len[id] = st[id][0].dist(st[id][1]);
	for (int i = 1;i <= id;i++)
	{
		f[i][0] = min(f[i - 1][0] + st[i - 1][0].dist(st[i][1]) + len[i],f[i - 1][1] + st[i - 1][1].dist(st[i][1]) + len[i]);
		f[i][1] = min(f[i - 1][0] + st[i - 1][0].dist(st[i][0]) + len[i],f[i - 1][1] + st[i - 1][1].dist(st[i][0]) + len[i]);
	}
	printf("%I64d\n",min(f[id][0],f[id][1]));
	return 0;
}