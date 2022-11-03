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
const int N = 5e3 + 10;
int low[N], dfn[N];
int in[N], s[N];
int cnt = 0, scccnt = 0, top = 0;
int belong[N];
vector<int> v[N];
int flag[N];
void tarjan(int x)
{
	low[x] = dfn[x] = ++cnt;
	in[x] = 1;
	s[top++] = x;
	for (auto &y : v[x])
	{
		if (dfn[y])
		{
			if (in[y])
			{
				low[x] = min(low[x], dfn[y]);
			}
		}
		else
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] == dfn[x])
	{
		scccnt++;
		int y = x;
		while (1)
		{
			y = s[--top];
			in[y] = 0;
			belong[y] = scccnt;
			if (x == y) break;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s;
	cin >> n >> m >> s;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (dfn[i]) continue;
		tarjan(i);
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto &j : v[i])
		{
			if (belong[i] == belong[j]) continue;
			flag[belong[j]] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= scccnt; i++)
	{
		if (i == belong[s]) continue;
		if (flag[i]) continue;
		if (flag[i] == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}