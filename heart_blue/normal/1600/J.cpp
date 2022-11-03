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
const int N = 1e3 + 10;
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int a[N][N];
int vis[N][N];
int cnt = 0;
int n, m;
void dfs(int x, int y)
{
	if (x < 0 || x >= n) return;
	if (y < 0 || y >= m) return;
	if (vis[x][y]) return;
	cnt++;
	vis[x][y] = 1;
	for (int o = 0; o < 4; o++)
	{
		if (a[x][y] >> o & 1) continue;
		dfs(x + dx[o], y + dy[o]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cnt = 0;
			dfs(i, j);
			if (cnt > 0) ans.push_back(cnt);
		}
	}
	sort(ans.rbegin(), ans.rend());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}