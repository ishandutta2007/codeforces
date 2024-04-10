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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int maxv[N];
int parent[N];
int son[N];
vector<int> v[N];
int ans[N];
int q[N];
void dfs1(int u)
{
	maxv[u] = 0;
	son[u] = 1;
	int maxson = 0;
	for (auto x : v[u])
	{
		dfs1(x);
		maxv[u] = max(maxv[u], maxv[x] + 1);
		maxson = max(maxson, son[x]);
		son[u] += son[x];
	}
	if (v[u].size() == 0)
	{
		ans[u] = u;
		return;
	}

	if (maxson * 2 <= son[u])
	{
		ans[u] = u;
		return;
	}
	int ret = -1;
	for (auto x : v[u])
	{
		int t = ans[x];
		do
		{
			int y = max(maxv[t], son[u] - son[t]);
			if (y * 2 <= son[u])
			{
				ret = t;
				break;
			}
			t = parent[t];
		} while (t != u);
		if (ret != -1) break;
	}
	ans[u] = ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	MEM(ans, 0);
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
		parent[i] = x;
	}
	dfs1(1);
	while (m--)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", ans[x]);
	}


	return 0;
}