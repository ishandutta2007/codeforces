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
const int N = 4e5 + 10;
vector<int> v[N];
int ans[N];
stack<int> s;
int in[N];
int getnext(int x, int y)
{
	if (x == -1 || y == -1) return -1;
	else return min(x + y, 2);
}
void dfs(int x)
{
	s.push(x);
	in[x]++;
	for (auto& y : v[x])
	{
		int o = getnext(ans[x], ans[y]);
		if (in[y]) o = -1;
		if (ans[y] != o)
		{
			ans[y] = o;
			dfs(y);
		}
	}
	s.pop();
	in[x]--;
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
		fill(ans + 1, ans + n + 1, 0);
		for (int i = 1; i <= n; i++) v[i].clear();
		while (m--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
		}
		ans[1] = 1;
		dfs(1);
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}