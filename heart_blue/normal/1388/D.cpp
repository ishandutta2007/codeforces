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
vector<int> v[N];
vector<int> vp[N];
int deg[N];
LL sum[N];
LL ans = 0;
void dfs(int x)
{
	for (auto& y : v[x])
	{
		dfs(y);
		sum[x] += max(0LL, sum[y]);
		if (sum[y] >= 0)
		{
			vp[y].push_back(x);
			deg[x]++;
		}
		else
		{
			vp[x].push_back(y);
			deg[y]++;
		}
	}
	ans += sum[x];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &sum[i]);
	vector<int> key;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == -1) key.push_back(i);
		else v[x].push_back(i);
	}
	for (auto& x : key)
		dfs(x);
	printf("%lld\n", ans);
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
			q.push(i);
	}
	vector<int> res;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		res.push_back(x);
		for (auto& y : vp[x])
		{
			if (deg[y]-- == 1)
				q.push(y);
		}
	}
	for (auto& x : res)
		printf("%d ", x);
	return 0;
}