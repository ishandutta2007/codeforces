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
const int N = 2e5 + 10;

int deg[N];
vector<int> v[N];
vector<pair<int, int>> vp;
int flag[N];
int sons[N];
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
		for (int i = 1; i <= n; i++) v[i].clear();
		memset(flag, 0, sizeof(int) * (n + 1));
		memset(deg, 0, sizeof(int) * (n + 1));
		vp.clear();
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
			vp.emplace_back(x, y);
			deg[x]++;
			deg[y]++;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] == 1)
				q.push(i);
			sons[i] = 1;
		}
		LL ans = 1LL * n * (n - 1);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			flag[x] = 1;
			for (auto& y : v[x])
			{
				if (--deg[y] == 1)
				{
					q.push(y);
				}
				if (deg[y] >= 0) sons[y] += sons[x];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] == 0)
			{
				ans -= 1LL * sons[i] * (sons[i] - 1) / 2;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}