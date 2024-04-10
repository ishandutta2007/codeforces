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

int n,q,v;
int ans[MAXN];
int laz1[MAXN << 2];

char tp;

bool laz2[MAXN << 2];

vector<int> pos[MAXN];
vector<int> neg[MAXN];

void fill(vector<int> &sou,vector<int> &tar)
{
	while (sou.size())
	{
		tar.push_back(sou.back());
		sou.pop_back();
	}
}

void upd1(int o,int v)
{
	laz2[o] = 0;
	laz1[o] = v;
}

void upd2(int o)
{
	laz2[o] ^= 1;
}

void pushdown(int o)
{
	if (laz1[o])
	{
		upd1(o << 1,laz1[o]);
		upd1(o << 1 | 1,laz1[o]);
		laz1[o] = 0;
	}
	if (laz2[o])
	{
		upd2(o << 1);
		upd2(o << 1 | 1);
		laz2[o] = 0;
	}
}

void modify1(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		upd1(o,v);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify1(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify1(o << 1 | 1,mid + 1,r,x,y,v);
}

void modify2(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
	{
		upd2(o);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify2(o << 1,l,mid,x,y);
	if (mid + 1 <= y)
		modify2(o << 1 | 1,mid + 1,r,x,y);
}

void calcans(int o,int l,int r)
{
	if (l == r)
	{
		if (laz1[o] == -1)
			fill(pos[l],neg[l]);
		if (laz1[o] == 1)
			fill(neg[l],pos[l]);
		if (laz2[o])
			swap(pos[l],neg[l]);
		for (int i = 0;i < pos[l].size();i++)
			ans[pos[l][i]] = l;
		for (int i = 0;i < neg[l].size();i++)
			ans[neg[l][i]] = -l;
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	calcans(o << 1,l,mid);
	calcans(o << 1 | 1,mid + 1,r);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> v;
		if (v >= 0)
			pos[v].push_back(i);
		else
			neg[-v].push_back(i);
	}
	while (q--)
	{
		cin >> tp >> v;
		if (tp == '>')
		{
			if (v >= 0)
				modify1(1,0,100000,v + 1,100000,-1);
			else
			{
				modify2(1,0,100000,0,-v - 1);
				modify1(1,0,100000,-v,100000,-1);
			}
		}
		else
		{
			if (v <= 0)
				modify1(1,0,100000,-v + 1,100000,1);
			else
			{
				modify2(1,0,100000,0,v - 1);
				modify1(1,0,100000,v,100000,1);
			}
		}
	}
	calcans(1,0,100000);
	for (int i = 1;i <= n;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}