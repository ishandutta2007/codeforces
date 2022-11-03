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
const int N = 3e5 + 10;
vector<int> v[N];
int sz[N];
int sons[N];
void dfs1(int x, int fa = -1)
{
	sz[x] = 1;
	sons[x] = 0;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs1(y, x);
		sons[x]++;
		sz[x] += sz[y];
	}
}
int dfs2(int x, int fa = -1)
{
	if (sons[x] == 0) return 0;
	if (sons[x] == 1) return sz[x] - 2;
	vector<int> key;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		key.push_back(y);
	}
	int s1 = key[0], s2 = key[1];
	return max(sz[s1] - 1 + dfs2(s2, x), sz[s2] - 1 + dfs2(s1, x));
}
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
		for (int i = 1; i <= n; i++)
			v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1);
		printf("%d\n", dfs2(1));
	}
	return 0;
}