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
vector<int> v[N];
int dis[N];
int deg[N];
int fa[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) v[i].clear();
		fill(dis + 1, dis + n + 1, 0);
		fill(deg + 1, deg + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &fa[i]);
			if (fa[i] == i) continue;
			v[fa[i]].push_back(i);
			deg[i]++;
		}
		for (int pre = 0, i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (pre != 0)
			{
				v[pre].push_back(x);
				deg[x]++;
			}
			pre = x;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] == 0)
			{
				q.push(i);
			}
		}
		int rest = n;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			rest--;
			for (auto& y : v[x])
			{
				if (deg[y]-- == 1)
					q.push(y);
				dis[y] = dis[x] + 1;
			}
		}
		if (rest > 0) puts("-1");
		else
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%d%c", dis[i] - dis[fa[i]], " \n"[i == n]);
			}
		}
	}
	return 0;
}