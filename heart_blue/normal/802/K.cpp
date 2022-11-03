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
const int N = 1e5 + 10;
int k;
vector<pair<int, int>> v[N];
pair<LL, LL> dfs(int x, int fa = 0)
{
	LL ret0 = 0, ret1 = 0;
	LL tot = 0;
	vector<pair<LL, LL>> key;
	LL maxv = 0;
	for (auto& [y, w] : v[x])
	{
		if (y == fa) continue;
		auto [res0, res1] = dfs(y, x);
		key.emplace_back(res0 + w, res1 + w);
	}
	sort(key.rbegin(), key.rend());
	for (int i = 0; i < k - 1; i++)
	{
		if (i == key.size()) break;
		ret0 += key[i].first;
	}
	LL sum = 0;
	for (int i = 0; i < k; i++)
	{
		if (i == key.size()) break;
		sum += key[i].first;
	}
	for (int i = 0; i < key.size(); i++)
	{
		if (i < k) ret1 = max(ret1, sum + key[i].second - key[i].first);
		else ret1 = max(ret1, sum + key[i].second - key[k - 1].first);
	}
	return { ret0,ret1 };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		v[x].emplace_back(y, w);
		v[y].emplace_back(x, w);
	}
	auto [res1, res2] = dfs(0);
	printf("%lld\n", max(res1, res2));
	return 0;
}