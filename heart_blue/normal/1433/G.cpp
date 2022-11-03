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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int dis[N][N];
vector<pair<int, int>> vp[N];
void solve(int d[], int x)
{
	d[x] = 0;
	typedef pair<int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.emplace(0, x);
	while (!pq.empty())
	{
		int x, val;
		tie(val, x) = pq.top();
		pq.pop();
		if (val != d[x]) continue;
		for (auto [y, w] : vp[x])
		{
			if (d[y] > d[x] + w)
			{
				d[y] = d[x] + w;
				pq.emplace(d[y], y);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	MEM(dis, 0x3f);
	vector<pair<int, int>> vp1, vp2;
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		vp[x].emplace_back(y, w);
		vp[y].emplace_back(x, w);
		vp1.emplace_back(x, y);
	}
	while (k--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp2.emplace_back(x, y);
	}
	for (int i = 1; i <= n; i++)
		solve(dis[i], i);
	int ans = INF * 2;
	for (auto [x, y] : vp1)
	{
		int sum = 0;
		for (auto [a, b] : vp2)
		{
			sum += min({ dis[a][b],dis[x][a] + dis[y][b], dis[x][b] + dis[y][a] });
		}
		ans = min(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}