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
	int n, m, k;
	cin >> n >> m >> k;
	if (4 * n * m - 2 * n - 2 * m < k) puts("NO"), exit(0);
	vector<pair<int, char>> v;
	vector<pair<int, char>> ans;
	if (n == 1 || m == 1)
	{
		if (n == 1)
			v.emplace_back(m - 1, 'R'), v.emplace_back(m - 1, 'L');
		if (m == 1)
			v.emplace_back(n - 1, 'D'), v.emplace_back(n - 1, 'U');
	}
	else
	{
		v.emplace_back(m - 1, 'R');
		v.emplace_back(m - 1, 'L');
		for (int i = 2; i < n; i++)
		{
			v.emplace_back(1, 'D');
			v.emplace_back(m - 1, 'R');
			v.emplace_back(m - 1, 'L');
		}
		v.emplace_back(1, 'D');
		for (int i = 2; i <= m; i++)
		{
			v.emplace_back(1, 'R');
			v.emplace_back(n - 1, 'U');
			v.emplace_back(n - 1, 'D');
		}
		v.emplace_back(m - 1, 'L');
		v.emplace_back(n - 1, 'U');
	}
	for (auto& p : v)
	{
		int o = min(p.first, k);
		k -= o;
		ans.emplace_back(o, p.second);
		if (k == 0) break;
	}
	puts("YES");
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d %c\n", p.first, p.second);
	return 0;
}