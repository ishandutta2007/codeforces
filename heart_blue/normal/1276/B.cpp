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
vector<int> v[N];
int a, b;
int flag = 0;
int vis[N];
int cnt = 0;
void dfs(int x)
{
	if (x == a) flag |= 1;
	if (x == b) flag |= 2;
	if (vis[x]) return;
	vis[x] = 1;
	cnt++;
	for (auto& y : v[x])
	{
		dfs(y);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		scanf("%d%d", &a, &b);
		for (int i = 1; i <= n; i++) v[i].clear();
		memset(vis, 0, sizeof(int) * (n + 1));
		while (m--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int tot1 = 0, tot2 = 0;
		vis[a] = vis[b] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i]) continue;
			cnt = 0;
			flag = 0;
			dfs(i);
			if (flag == 1) tot1 += cnt;
			if (flag == 2) tot2 += cnt;
		}
		printf("%lld\n", 1LL * tot1 * tot2);
	}
	return 0;
}