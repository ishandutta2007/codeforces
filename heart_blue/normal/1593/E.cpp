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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
vector<int> v[N];
int ans[N];
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i <= n; i++) ans[i] = 0;
		for (int i = 1; i <= n; i++) deg[i] = 0;
		queue<int> q;
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
			deg[x]++;
			deg[y]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] == 1)
			{
				q.push(i);
				ans[i] = 1;
			}
		}
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (auto& y : v[x])
			{
				if (ans[y]) continue;
				deg[y]--;
				if (deg[y] <= 1)
				{
					ans[y] = ans[x] + 1;
					q.push(y);
				}
			}
		}
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ans[i] > k)
				tot++;
		}
		printf("%d\n", tot);
	}
	return 0;
}