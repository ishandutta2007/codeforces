#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int d[N * 100];
int pre[N * 100];
int a[40][40];
int dis(pair<int, int> p1, pair<int, int> p2 = { 0,0 })
{
	int x = p1.first - p2.first;
	int y = p1.second - p2.second;
	return x * x + y * y;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int x, y;
	cin >> x >> y;
	int n;
	cin >> n;
	vector<pair<int, int>> pos(n);
	for (auto &p : pos)
	{
		cin >> p.first >> p.second;
		p.first -= x;
		p.second -= y;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			a[i][j] = a[j][i] = dis(pos[i]) + dis(pos[j]) + dis(pos[i], pos[j]);
		}
	}
	MEM(pre, -1);
	MEM(d, 0x3f);
	d[0] = 0;
	int tot = 1 << n;
	for (int i = 0; i < tot; i++)
	{
		vector<int> v;
		if (d[i] == 0x3f3f3f3f) continue;
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1) continue;
			v.push_back(j);
		}
		for (int j = 0; j < v.size(); j++)
		{
			int x = v[0], y = v[j];
			int o = (1 << x) | (1 << y) | i;
			int &res = d[o];
			if (res > d[i] + a[x][y])
			{
				res = d[i] + a[x][y];
				pre[o] = x << 16 | y;
			}
		}
	}
	int s = tot - 1;
	vector<int> ans;
	printf("%d\n", d[s]);
	while (pre[s] != -1)
	{
		int x = pre[s] >> 16;
		int y = pre[s] & (0xffff);
		if (x != y) s ^= (1 << x) ^ (1 << y);
		else s ^= 1 << x;
		ans.push_back(0);
		ans.push_back(x + 1);
		ans.push_back(y + 1);
		ans.push_back(0);
	}
	int cur = -1;
	for (auto &x : ans)
	{
		if (x == cur) continue;
		printf("%d ", x);
		cur = x;
	}

	return 0;
}