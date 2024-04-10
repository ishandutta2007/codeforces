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

typedef long long ll;

const int MAXN = 200005;

struct Coord
{
	int x,y;
};

int n,tp,x,y,id,cnt;

vector<Coord> c[MAXN];
map<ll,int> match;
map<pair<int,int>,int> ans,spj;

int gcd(int a,int b)
{
	return b ? gcd(b,a % b) : a;
}

void red(int &x,int &y)
{
	int g = gcd(x,y);
	x /= g;
	y /= g;
}

void modify(int x,int y,int v)
{
	red(x,y);
	ans[make_pair(x,y)] += v;
}

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d%d",&tp,&x,&y);
		ll len = x * x + y * y;
		if (!match[len])
			match[len] = ++id;
		len = match[len];
		if (tp == 1)
		{
			cnt++;
			for (int i = 0;i < c[len].size();i++)
				modify(c[len][i].x + x,c[len][i].y + y,1);
			c[len].push_back((Coord){x,y});
			red(x,y);
			spj[make_pair(x,y)]++;
		}
		if (tp == 2)
		{
			cnt--;
			int pos = -1;
			for (int i = 0;i < c[len].size();i++)
			{
				if (c[len][i].x != x || c[len][i].y != y)
					modify(c[len][i].x + x,c[len][i].y + y,-1);
				else
					pos = i;
			}
			c[len].erase(c[len].begin() + pos);
			red(x,y);
			spj[make_pair(x,y)]--;
		}
		if (tp == 3)
		{
			red(x,y);
			printf("%d\n",cnt - 2 * ans[make_pair(x,y)] - spj[make_pair(x,y)]);
		}
	}
	return 0;
}