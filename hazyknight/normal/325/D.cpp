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

const int MAXN = 300005;

int r,c,n,id,ans;
int fa[MAXN];
int sz[MAXN];
int pre[MAXN];
int match[3005][3005];
int dr[8][2] = 
{
	-1,-1,
	-1,0,
	-1,1,
	0,-1,
	0,1,
	1,-1,
	1,0,
	1,1,
};

vector<pair<int*,int> > rollback;

int getroot(int u)
{
	return u == fa[u] ? u : getroot(fa[u]);
}

bool getval(int u)
{
	return u == fa[u] ? 0 : getval(fa[u]) ^ pre[u];
}

void setv(int &a,int b)
{
	rollback.push_back(make_pair(&a,a));
	a = b;
}

bool merge(int u,int v,bool tp)
{
	int ru = getroot(u),rv = getroot(v);
	if (ru == rv)
		return !getval(u) ^ getval(v) ^ tp;
	if (sz[ru] > sz[rv])
	{
		swap(u,v);
		swap(ru,rv);
	}
	setv(pre[ru],getval(u) ^ getval(v) ^ tp);
	setv(fa[ru],rv);
	setv(sz[rv],sz[ru] + sz[rv]);
	return 1;
}

int main()
{
	scanf("%d%d%d",&r,&c,&n);
	while (n--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		if (match[x][y])
		{
			ans++;
			continue;
		}
		match[x][y] = ++id;
		fa[id] = id;
		sz[id] = 1;
		rollback.clear();
		bool ok = 1;
		for (int i = 0;i < 8;i++)
		{
			int tx = x + dr[i][0],ty = (y + dr[i][1] + c) % c;
			if (tx >= 0 && tx < r && match[tx][ty] && !merge(id,match[tx][ty],y + dr[i][1] >= c || y + dr[i][1] < 0))
			{
				ok = 0;
				match[x][y] = 0;
				id--;
				while (rollback.size())
				{
					*rollback.back().first = rollback.back().second;
					rollback.pop_back();
				}
				break;
			}
		}
		ans += ok;
	}
	printf("%d\n",ans);
	return 0;
}