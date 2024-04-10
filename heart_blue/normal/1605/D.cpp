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
const int N = 2e5 + 10;
vector<int> v[N];
vector<int> vp[2];
int ans[N];
int flag[N];
void bfs(int n)
{
	fill(flag + 1, flag + n + 1, 0);
	flag[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		vp[flag[x] & 1].push_back(x);
		for (auto& y : v[x])
		{
			if (flag[y]) continue;
			flag[y] = flag[x] + 1;
			q.push(y);
		}
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
		for (int i = 1; i <= n; i++) v[i].clear();
		vp[0].clear();
		vp[1].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		bfs(n);
		int cur = n;
		while (cur > 0)
		{
			int l = cur;
			while (l != (l & -l))
				l -= l & -l;
			int len = cur - l + 1;
			int o = 0;
			if (vp[o].size() < len) o ^= 1;
			while (len--)
			{
				ans[vp[o].back()] = cur--;
				vp[o].pop_back();
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}