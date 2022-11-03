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
const int N = 4e5 + 10;
vector<int> ans[N];
vector<int> v[N];
int tot;
int vis[N];
int cnt = 0;
void dfs(int x)
{
	vis[x] = 1;
	ans[cnt++ / tot].push_back(x);
	for (auto &y : v[x])
	{
		if (vis[y]) continue;
		dfs(y);
		ans[cnt++ / tot].push_back(x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	tot = (2 * n + k - 1) / k;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		cnt = (cnt + tot - 1) / tot * tot;
		dfs(i);
	}
	for (int i = 0; i < k; i++)
	{
		if (ans[i].empty()) ans[i].push_back(1);
		printf("%d", ans[i].size());
		for (auto &x : ans[i]) printf(" %d", x);
		puts("");
	}
	return 0;
}