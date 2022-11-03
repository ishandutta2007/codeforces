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
set<int> s[N];
vector<int> key;
bool dfs(int x, int fa = 0)
{
	s[x].erase(fa);
	vector<int> v;
	for (auto& y : s[x])
	{
		if (y == fa)
			continue;
		if (dfs(y, x))
			v.push_back(y);
	}
	for (auto& y : v)
	{
		s[x].erase(y);
		s[y].erase(x);
	}
	if (s[x].empty()) return false;
	bool ret = true;
	for (auto& y : s[x])
	{
		if (!s[y].empty())
			ret = false;
	}
	if (ret) key.push_back(x);
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) s[i].clear();
		key.clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			s[x].emplace(y);
			s[y].emplace(x);
		}
		dfs(1);
		if (key.empty() || key.back() != 1) key.push_back(1);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (s[i].empty())
				cnt++;
		printf("%d\n", cnt - key.size() + 1);
	}
	return 0;
}