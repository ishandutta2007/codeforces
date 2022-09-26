#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int ok(pair<int,int> a,pair<int,int> b)
{
	if (a.first > a.second)
		swap(a.first,a.second);
	if (b.first > b.second)
		swap(b.first,b.second);
	if (a.first == b.first && a.second == b.second)
		return 0;
	if (a.first == b.first)
		return a.first;
	if (a.first == b.second)
		return a.first;
	if (a.second == b.first)
		return a.second;
	if (a.second == b.second)
		return b.second;
	return 0;
}

int n,m;
pair<int,int> a[20],b[20];

int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i].first >> a[i].second;
	for (int i = 1;i <= m;i++)
		cin >> b[i].first >> b[i].second;
	bool oka = true,okb = true,okme = true;
	for (int i = 1;i <= n;i++)
	{
		int cnt = 0;
		for (int j = 1;j <= m;j++)
		{
			int ret = ok(a[i],b[j]);
			if (!ret)
				continue;
			if (!cnt)
				cnt = ret;
			if (cnt != ret)
			{
				oka = false;
				break;
			}
		}
	}
	for (int i = 1;i <= m;i++)
	{
		int cnt = 0;
		for (int j = 1;j <= n;j++)
		{
			int ret = ok(b[i],a[j]);
			if (!ret)
				continue;
			if (!cnt)
				cnt = ret;
			if (cnt != ret)
			{
				okb = false;
				break;
			}
		}
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			int ret = ok(a[i],b[j]);
			if (!ret)
				continue;
			if (!cnt)
				cnt = ret;
			if (cnt != ret)
			{
				okme = false;
				break;
			}
		}
	if (okme && oka && okb)
	{
		cout << cnt << endl;
		return 0;
	}
	if (oka && okb)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}