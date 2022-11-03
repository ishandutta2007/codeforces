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
vector<int> v[N];
int ans[N];
int deg[N];
int flag[N];
int c[N];
void dfs1(int x, int fa = -1, int o = 1)
{
	if (c[x] == 0) c[x] = o;
	else return;
	for (auto& y : v[x])
	{
		dfs1(y, x, o * -1);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	v[0].push_back(1);

	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) v[i].clear(), deg[i] = 0;
		vector<int> key;
		for (int i = 1; i <= n; i++)
			key.push_back(i);
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
			deg[x]++;
			deg[y]++;
		}
		fill(c + 1, c + n + 1, 0);
		dfs1(1);
		for (int i = 1; i <= n; i++)
			printf("%d%c", c[i] * deg[i], " \n"[i == n]);
	}
	return 0;
}