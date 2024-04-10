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
const int N = 2e3 + 10;
char s[N];
char str[N][N];
int ans[N * 2];
vector<pair<int, int>> vp[N * 2];
void dfs(int x, int o = 0)
{
	if (ans[x] != -1)
	{
		if (ans[x] != o)
			puts("-1"), exit(0);
		return;
	}
	ans[x] = o;
	for (auto& [y, val] : vp[x])
	{
		dfs(y, o ^ val);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		for (int j = 1; j <= n; j++)
		{
			str[i][j] ^= s[j] - '0';
		}
	}
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int o = (str[i][j] - '0');
			if (s[i] == '1' && s[j] == '1')
			{
				vp[i].emplace_back(j + n, o);
				vp[j + n].emplace_back(i, o);
			}
			else if (s[j] == '1')
			{
				vp[0].emplace_back(i, o);
				vp[i].emplace_back(0, o);
			}
			else if (s[i] == '1')
			{
				vp[0].emplace_back(j + n, o);
				vp[j + n].emplace_back(0, o);
			}
			else if (o)
			{
				puts("-1");
				exit(0);
			}
		}
	}
	MEM(ans, -1);
	vector<int> res;
	for (int i = 0; i <= 2 * n; i++)
	{
		if (ans[i] == -1)
			dfs(i, 0);
		if (ans[i] == 1)
			res.push_back(i);
	}
	printf("%d\n", res.size());
	for (auto& x : res)
	{
		if (x <= n) printf("row %d\n", x - 1);
		else printf("col %d\n", x - n - 1);
	}
	return 0;
}