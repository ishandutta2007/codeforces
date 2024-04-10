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
#include <regex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
vector<int> vp[N];
int flag[N];
int n;
int m;
void check(vector<int>& v1, vector<int>& v2)
{
	int minv = min(v1.size(), v2.size());
	for (int i = 0; i < minv; i++)
	{
		int x = v1[i];
		int y = v2[i];
		if (x != y)
		{
			if (x < y) vp[y].emplace_back(x);
			else
			{
				vp[m + 1].push_back(x);
				vp[y].push_back(0);
			}
			return;
		}
	}
	if (v1.size() > v2.size()) puts("No"), exit(0);
}
void dfs(int x)
{
	if (flag[x]) return;
	flag[x] = 1;
	for (auto& y : vp[x])
	{
		dfs(y);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++)
	{
		int sz;
		scanf("%d", &sz);
		v[i].resize(sz);
		for (auto& x : v[i])
			scanf("%d", &x);
	}
	for (int i = 1; i < n; i++)
		check(v[i], v[i + 1]);
	dfs(m + 1);
	if (flag[0])
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("%d\n", count(flag + 1, flag + m + 1, 1));
	for (int i = 1; i <= m; i++)
	{
		if (flag[i] == 0) continue;
		printf("%d ", i);
	}
	return 0;
}