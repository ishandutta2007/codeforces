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
int dis1[N];
int dis2[N];
int flag[N];
void bfs(int x, int dis[N])
{
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto& y : v[x])
		{
			if (dis[y]) continue;
			dis[y] = dis[x] + 1;
			q.push(y);
		}
	}
	dis[x] = 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<int> vp;
	for (int i = 1; i <= k; i++)
	{
		int x;
		scanf("%d", &x);
		vp.emplace_back(x);
	}
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	bfs(1, dis1);
	bfs(n, dis2);
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0) continue;
		v1.push_back(dis1[i]);
		v2.push_back(dis2[i]);
	}
	sort(vp.rbegin(), vp.rend(), [](int x, int y)->bool
		{
			return dis1[x] + dis2[y] < dis2[x] + dis1[y];
		});
	int ans = 0;
	int maxv = -INF;
	for (auto& x : vp)
	{
		ans = max(ans, dis1[x] + maxv + 1);
		maxv = max(maxv, dis2[x]);
	}
	ans = min(ans, dis1[n]);
	printf("%d\n", ans);
	return 0;
}