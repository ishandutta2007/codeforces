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
const int N = 2e5 + 10;
vector<int> v[N];
int flag[N];
int pre[N];
void build(vector<int>& ans, int x)
{
	while (x)
	{
		ans.push_back(x);
		x = pre[x];
	}
	reverse(ans.begin(), ans.end());
}
void output(vector<int>& ans)
{
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
}
void dfs(int x, int o)
{
	flag[x] = o;
	for (auto& y : v[x])
	{
		if (flag[x] > 0 && flag[y] > 0 && flag[x] != flag[y])
		{
			puts("Possible");
			vector<int> ans1, ans2;
			build(ans1, y);
			build(ans2, x);
			ans2.push_back(y);
			output(ans1);
			output(ans2);
			exit(0);
		}
		if (flag[y]) continue;
		pre[y] = x;
		dfs(y, o);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	flag[s] = -1;
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	for (auto& x : v[s])
		flag[x] = x, pre[x] = s;
	for (auto& x : v[s])
		dfs(x, x);
	puts("Impossible");
	return 0;
}