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
vector<int> vp1[N], vp2[N];
int dis[N];
int ans[N];
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
		for (int i = 1; i <= n; i++) vp1[i].clear(), vp2[i].clear();
		for (int i = 1; i <= n; i++) dis[i] = INF;
		while (m--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			vp1[x].push_back(y);
			vp2[y].push_back(x);
		}
		dis[1] = 0;
		queue<int> q;
		q.push(1);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (auto& y : vp1[x])
			{
				if (dis[y] > dis[x] + 1)
				{
					dis[y] = dis[x] + 1;
					q.push(y);
				}
			}
		}
		for (int i = 1; i <= n; i++) ans[i] = dis[i];
		typedef pair<int, int> Node;
		priority_queue<Node, vector<Node>, greater<Node>> pq;
		for (int i = 1; i <= n; i++)
		{
			for (auto& x : vp1[i])
			{
				if (dis[x] < dis[i])
				{
					ans[i] = min(ans[i], dis[x]);
				}
			}
			pq.emplace(ans[i], i);
		}
		while (!pq.empty())
		{
			auto [res, x] = pq.top();
			pq.pop();
			if (res > ans[x]) continue;
			for (auto& y : vp2[x])
			{
				if (dis[y] < dis[x] && ans[y] > ans[x])
				{
					ans[y] = ans[x];
					pq.emplace(ans[y], y);
				}
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}