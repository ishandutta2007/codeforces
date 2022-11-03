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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> ans[N], v[N];
int cnt = 0;
void dfs(vector<int>& key, int x)
{
	key.push_back(x);
	if (v[x].empty())
	{
		ans[cnt++] = key;
		key.clear();
	}
	for (auto& y : v[x])
	{
		dfs(key, y);
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
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			v[i].clear();
		int rt = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x == i)
			{
				rt = i;
				continue;
			}
			v[x].push_back(i);
		}
		vector<int> key;
		cnt = 0;
		dfs(key, rt);
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; i++)
		{
			printf("%d\n", ans[i].size());
			for (auto& x : ans[i])
				printf("%d ", x);
			puts("");
		}
	}

	return 0;
}