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
map<int, LL> mc[N];
vector<int> v[N];
LL w[N];
LL dfs(int x, int k)
{
	if (k == 0) return 0;
	if (mc[x].count(k)) return mc[x][k];
	vector<LL> key;
	LL& ret = mc[x][k] = w[x] * k;
	for (auto& y : v[x])
	{
		LL res = dfs(y, k / v[x].size());
		if (k % v[x].size())
			key.push_back(dfs(y, k / v[x].size() + 1) - res);
		ret += res;
	}
	if (key.empty())
		return ret;
	sort(key.rbegin(), key.rend());
	for (int i = 0; i < k % v[x].size(); i++)
		ret += key[i];
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
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) mc[i].clear();
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 2; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
		}
		for (int i = 1; i <= n; i++)
			scanf("%lld", &w[i]);
		printf("%lld\n", dfs(1, k));
	}
	return 0;
}