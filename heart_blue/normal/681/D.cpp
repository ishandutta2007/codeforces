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
int deg1[N], deg2[N];
stack<int> s;
int flag[N];
int a[N];
void dfs(int x)
{
	if (!s.empty())
	{
		if (a[x] != s.top()) v2[a[x]].push_back(s.top()), deg2[s.top()]++;
		if (flag[x]) v2[x].push_back(s.top()), deg2[s.top()]++;
	}
	if (flag[x]) s.push(x);
	for (auto &y : v1[x])
	{
		dfs(y);
	}
	if (flag[x]) s.pop();

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v1[x].push_back(y);
		deg1[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		flag[a[i]] = 1;
	}
	int tot = count(flag + 1, flag + n + 1, 1);
	for (int i = 1; i <= n; i++)
	{
		if (deg1[i]) continue;
		dfs(i);
	}
	vector<int> ans;
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg2[i] == 0 && flag[i])
			q.push(i);
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		ans.push_back(x);
		for (auto &y : v2[x])
		{
			if (--deg2[y] == 0) q.push(y);
		}
	}
	if (ans.size() != tot)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n", ans.size());
	for (auto &x : ans) printf("%d\n", x);

	return 0;
}