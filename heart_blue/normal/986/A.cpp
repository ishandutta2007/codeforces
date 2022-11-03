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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int dis[N];
int type[N];
vector<int> ans[N];
int n, m, k, s;
void solve(int o)
{
	MEM(dis, 0x3f);
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (type[i] == o)
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
		ans[i].push_back(dis[i]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &type[i]);
	}
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= k; i++)
	{
		solve(i);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(ans[i].begin(), ans[i].end());
		LL sum = 0;
		for (int j = 0; j < s; j++) sum += ans[i][j];
		printf("%lld ", sum);
	}
	return 0;
}