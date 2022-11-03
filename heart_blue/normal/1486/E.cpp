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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int dis[N][51];
vector<pair<int, int>> vp[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dis, 0x3f);
	MEM(ans, -1);
	ans[1] = 0;
	int inf = dis[0][0];
	using Node = tuple<int, int, int>;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		vp[x].emplace_back(y, w);
		vp[y].emplace_back(x, w);
	}
	pq.emplace(0, 1, 0);
	dis[1][0] = 0;
	while (!pq.empty())
	{
		auto [d, x, w1] = pq.top();
		pq.pop();
		if (w1 == 0 && ans[x] == -1)
			ans[x] = d;
		if (d != dis[x][w1]) continue;
		for (auto [y, w2] : vp[x])
		{
			int s = (w1 + w2) * (w1 + w2);
			int o = w2;
			if (w1 == 0) s = 0;
			else o = 0;
			if (dis[y][o] > d + s)
			{
				dis[y][o] = d + s;
				pq.emplace(d + s, y, o);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}