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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v1[N], v2[N];
int f[N];
int vis[N];
int ans[N];
void dfs1(int x, vector<int> v[N], int cnt = 0)
{
	if (vis[x]) return;
	if (f[x] == 1 && cnt == 1) return;
	if (f[x] == 1) cnt++;
	vis[x] = 1;
	ans[x] |= 1;
	for (auto& y : v[x])
	{
		dfs1(y, v, cnt);
	}
}
void dfs2(int x, vector<int> v[N])
{
	if (vis[x]) return;
	vis[x] = 1;
	ans[x] |= 2;
	if (f[x] == 1) return;
	for (auto& y : v[x])
	{
		dfs2(y, v);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v1[x].push_back(y);
		v2[y].push_back(x);
	}
	MEM(vis, 0);
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == 1)
			dfs1(i, v1);
	}
	MEM(vis, 0);
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == 2)
			dfs2(i, v2);
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i] == 3 ? 1 : 0);
	return 0;
}