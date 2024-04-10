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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e3 + 10;
int dp[N][N];
int flag[N][N];
int key[N][N];
vector<int> vp[N];
pair<int, int> p[N];
int dfs(int l, int r)
{
	if (l > r) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	dp[l][r] = dfs(l + 1, r);
	for (auto id : vp[l])
	{
		auto [x, y] = p[id];
		if (y >= r) continue;
		if (dp[l][r] < dfs(x, y) + dfs(y, r))
		{
			dp[l][r] = dfs(x, y) + dfs(y, r);
			key[l][r] = id;
		}
	}
	if (flag[l][r])
		dp[l][r]++;
	return dp[l][r];
}
void output(int l, int r)
{
	if (l > r) return;
	if (flag[l][r])
		printf("%d ", flag[l][r]);
	if (key[l][r])
	{
		auto [x, y] = p[key[l][r]];
		output(l, y);
		output(y, r);
	}
	else
		output(l + 1, r);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		int c, r;
		scanf("%d%d", &c, &r);
		v.emplace_back(c + r);
		v.emplace_back(c - r);
		p[i] = { c - r,c + r };
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 1; i <= n; i++)
	{
		auto& [x, y] = p[i];
		x = upper_bound(v.begin(), v.end(), x) - v.begin();
		y = upper_bound(v.begin(), v.end(), y) - v.begin();
		vp[x].push_back(i);
		flag[x][y] = i;
	}
	int sz = v.size();
	MEM(dp, -1);
	printf("%d\n", dfs(1, sz));
	output(1, sz);
	return 0;
}