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
const int N = 2e3 + 10;
vector<int> vp[N];
vector<int> ans[N];
int res[N];
int c[N];
void dfs(int x)
{
	for (auto& y : vp[x])
	{
		dfs(y);
		for (auto& val : ans[y])
			ans[x].push_back(val);
	}
	if (c[x] > ans[x].size()) puts("NO"), exit(0);
	ans[x].insert(ans[x].begin() + c[x], x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int rt = 1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d%d", &x, &c[i]);
		vp[x].push_back(i);
		if (x == 0)
			rt = i;
	}
	dfs(rt);
	puts("YES");
	for (int i = 0; i < ans[rt].size(); i++)
	{
		res[ans[rt][i]] = i + 1;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", res[i]);
	return 0;
}