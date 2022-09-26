#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;

int area(pair<int,int> a,pair<int,int> b,pair<int,int> c)
{
	return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);
}

pair<int,int> a[4],b[4];

bool inside(pair<int,int> p,pair<int,int> *s)
{
	bool pos = false,neg = false;
	for (int i = 0;i < 4;i++)
	{
		int v = area(p,s[i],s[(i + 1) % 4]);
		if (v < 0)
			neg = true;
		if (v > 0)
			pos = true;
	}
	if (pos && neg)
		return false;
	return true;
}

int main()
{
	int MINx = 101,MAXx = -101,MINy = 101,MAXy = -101;
	for (int i = 0;i < 4;i++)
	{
		cin >> a[i].first >> a[i].second;
		MINx = min(MINx,a[i].first);
		MINy = min(MINy,a[i].second);
		MAXx = max(MAXx,a[i].first);
		MAXy = max(MAXy,a[i].second);
	}
	for (int i = 0;i < 4;i++)
		cin >> b[i].first >> b[i].second;
	for (int i = MINx;i <= MAXx;i++)
		for (int j = MINy;j <= MAXy;j++)
			if (inside(make_pair(i,j),b))
			{
				cout << "YES" << endl;
				return 0;
			}
	cout << "NO" << endl; 
	return 0;
}