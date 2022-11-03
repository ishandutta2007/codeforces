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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int low[N], dfn[N];
int cnt = 1;
vector<int> v[N];
int dis[N];
int key = N;
void tarjan(int x, int fa = -1)
{
	low[x] = dfn[x] = cnt++;
	int flag = 0;
	for (auto &y : v[x])
	{
		if (y == fa)
		{
			if (!flag)
			{
				flag = 1;
				continue;
			}
		}
		if (dfn[y]) low[x] = min(low[x], dfn[y]);
		else
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] < dfn[x])
	{
		key = min(low[x], dfn[x]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	MEM(dfn, 0);
	tarjan(1);
	MEM(dis, 0x3f);
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (low[i] == key)
		{
			dis[i] = 0;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto &y : v[x])
		{
			if (dis[y] > dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << ' ';
	}
	return 0;
}