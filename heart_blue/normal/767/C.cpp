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
const int N = 1e6 + 10;
int in[N], out[N];
int sum[N];
int dfn = 0;
vector<int> v[N];
int tot = 0;
vector<int> v1, v2;
int dfs(int x)
{
	in[x] = ++dfn;
	for (auto &y : v[x])
	{
		sum[x] += dfs(y);
	}
	out[x] = dfn;
	if (sum[x] == tot) v1.push_back(x);
	if (sum[x] == tot * 2) v2.push_back(x);
	return sum[x];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int root = 0;
	for (int i = 1; i <= n; i++)
	{
		int p;
		scanf("%d%d", &p, &sum[i]);
		v[p].push_back(i);
		tot += sum[i];
		if (p == 0) root = i;
	}
	if (tot % 3 != 0)
	{
		puts("-1");
		return 0;
	}
	tot /= 3;
	dfs(root);
	auto cmp = [&](int x, int y) -> bool
	{
		return in[x] < in[y];
	};
	if (!v1.empty()) sort(v1.begin(), v1.end(), cmp);
	if (!v2.empty()) sort(v2.begin(), v2.end(), cmp);
	stack<int> s;
	for (auto &x : v1)
	{
		while (!s.empty())
		{
			int y = s.top();
			if (in[y] <= in[x] && in[x] <= out[y])
			{
				s.pop();
				continue;
			}
			printf("%d %d\n", x, y);
			return 0;
		}
		s.push(x);
	}
	int p = 0;
	for (auto x : v2)
	{
		if (x == root) continue;
		while (p < v1.size())
		{
			int y = v1[p];
			if (x == y || in[y] < in[x]) p++;
			else if (in[y] > out[x]) break;
			else
			{
				printf("%d %d\n", x, y);
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}