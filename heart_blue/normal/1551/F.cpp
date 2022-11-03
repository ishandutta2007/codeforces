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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
vector<int> v[N];
void dfs(int x, vector<int>& cnt, int fa = 0, int d = 0)
{
	cnt[d]++;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs(y, cnt, x, d + 1);
	}
}
vector<int> multy(vector<int>& v1, vector<int>& v2)
{
	while (v1.size() > 1 && v1.back() == 0) v1.pop_back();
	while (v2.size() > 1 && v2.back() == 0) v2.pop_back();
	vector<int> ret(v1.size() + v2.size() - 1);
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			ret[i + j] = (ret[i + j] + 1LL * v1[i] * v2[j]) % INF;
		}
	}
	return ret;
}
int solve(vector<int>& vp, int k)
{
	if (vp.size() < k) return 0;
	vector<int> ret;
	ret.push_back(1);
	for (auto& x : vp)
	{
		vector<int> v{ 1,x };
		ret = multy(ret, v);
	}
	if (ret.size() <= k) return 0;
	else return ret[k];
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
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if (k == 2)
		{
			printf("%d\n", n * (n - 1) / 2);
			continue;
		}
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			vector<vector<int>> key(n);
			for (auto& j : v[i])
			{
				vector<int> cnt(n, 0);
				dfs(j, cnt, i, 0);
				for (int k = 0; k < n; k++)
				{
					if (cnt[k] > 0)
						key[k].push_back(cnt[k]);
				}
			}
			for (auto& vp : key)
			{
				ans += solve(vp, k);
			}
		}
		printf("%lld\n", ans % INF);
	}
	return 0;
}