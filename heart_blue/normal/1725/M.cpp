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
const int N = 2e5 + 10;
vector<pair<int, int>> vp[N][2];
LL dis[N][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		vp[x][0].emplace_back(y, w);
		vp[y][1].emplace_back(x, w);
	}
	MEM(dis, 0x3f);
	LL inf = dis[0][0];
	using Node = tuple<LL, int, int>;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.emplace(0LL, 1, 0);
	while (!pq.empty())
	{
		auto [d, x, o] = pq.top();
		pq.pop();
		if (d > dis[x][o]) continue;
		if (o == 0 && dis[x][1] > d)
		{
			dis[x][1] = d;
			pq.emplace(d, x, 1);
		}
		for (auto& [y, w] : vp[x][o])
		{
			if (dis[y][o] > d + w)
			{
				dis[y][o] = d + w;
				pq.emplace(d + w, y, o);
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		LL res = dis[i][1];
		if (res == inf)
			res = -1;
		printf("%lld%c", res, " \n"[i == n]);
	}
	return 0;
}