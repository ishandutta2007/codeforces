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
#include <cassert>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int dis[3][N];
vector<int> v[N];
LL sum[N];
void init(int x, int n, int dis[N])
{
	memset(dis, 0x3f, sizeof(int) * (n + 1));
	queue<int> q;
	q.push(x);
	dis[x] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto& y : v[x])
		{
			if (dis[y] > dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		for (int i = 1; i <= n; i++)
			v[i].clear();
		for (int i = 1; i <= m; i++)
		{
			scanf("%lld", &sum[i]);
		}
		sort(sum + 1, sum + m + 1);
		for (int i = 1; i <= m; i++)
			sum[i] += sum[i - 1];
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		
		init(a, n, dis[0]);
		init(b, n, dis[1]);
		init(c, n, dis[2]);
		LL ans = INF * INF;
		for (int i = 1; i <= n; i++)
		{
			int o = dis[0][i] + dis[1][i] + dis[2][i];
			ans = min(ans, sum[dis[1][i]] + (o <= m ? sum[o] : 4 * INF * INF));
		}
		printf("%lld\n", ans);
	}
	return 0;
}