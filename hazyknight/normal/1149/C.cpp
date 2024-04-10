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

const int MAXN = 200005;

struct Node
{
	int MAXv,MINv,MAXl,MAXr,MAXans,laz;
}node[MAXN << 2];

int n,q;
int a[MAXN];

string s;

void add(int o,int v)
{
	node[o].MAXv += v;
	node[o].MINv += v;
	node[o].MAXl -= v;
	node[o].MAXr -= v;
	node[o].laz += v;
}

void pushdown(int o)
{
	if (node[o].laz)
	{
		add(o << 1,node[o].laz);
		add(o << 1 | 1,node[o].laz);
		node[o].laz = 0;
	}
}

void update(int o)
{
	node[o].MAXv = max(node[o << 1].MAXv,node[o << 1 | 1].MAXv);
	node[o].MINv = min(node[o << 1].MINv,node[o << 1 | 1].MINv);
	node[o].MAXl = max(node[o << 1].MAXl,node[o << 1 | 1].MAXl);
	node[o].MAXl = max(node[o].MAXl,node[o << 1].MAXv - 2 * node[o << 1 | 1].MINv);
	node[o].MAXr = max(node[o << 1].MAXr,node[o << 1 | 1].MAXr);
	node[o].MAXr = max(node[o].MAXr,node[o << 1 | 1].MAXv - 2 * node[o << 1].MINv);
	node[o].MAXans = max(node[o << 1].MAXans,node[o << 1 | 1].MAXans);
	node[o].MAXans = max(node[o].MAXans,node[o << 1].MAXl + node[o << 1 | 1].MAXv);
	node[o].MAXans = max(node[o].MAXans,node[o << 1 | 1].MAXr + node[o << 1].MAXv);
}

void buildtree(int o,int l,int r)
{
	if (l == r)
	{
		node[o].MAXv = node[o].MINv = a[l];
		node[o].MAXl = node[o].MAXr = -a[l];
		node[o].MAXans = 0;
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	update(o);
}

void modify(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		add(o,v);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,v);
	update(o);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> q >> s;
	n = 2 * (n - 1);
	for (int i = 1;i <= n;i++)
		a[i] = a[i - 1] + (s[i - 1] == '(' ? 1 : -1);
	buildtree(1,1,n);
	cout << node[1].MAXans << endl;
	for (int x,y,i = 1;i <= q;i++)
	{
		cin >> x >> y;
		if (s[x - 1] != s[y - 1])
		{
			if (x > y)
				swap(x,y);
			if (s[x - 1] == '(')
				modify(1,1,n,x,y - 1,-2);
			else
				modify(1,1,n,x,y - 1,2);
			swap(s[x - 1],s[y - 1]);
		}
		cout << node[1].MAXans << endl;
	}
	return 0;
}