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
vector<tuple<int, int, int>> vp[N];
int ans[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		vp[x].emplace_back(y, w, i);
		vp[y].emplace_back(x, w, -i);
		sum[x] += w;
		sum[y] += w;
	}
	for (int i = 1; i <= n; i++) sum[i] /= 2;
	sum[1] = sum[n] = -1;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto& p : vp[x])
		{
			int y, w, pos;
			tie(y, w, pos) = p;
			if (ans[abs(pos)]) continue;
			sum[y] -= w;
			ans[abs(pos)] = pos;
			if (sum[y] == 0)
				q.push(y);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (ans[i] > 0) puts("0");
		else puts("1");
	}
	return 0;
}