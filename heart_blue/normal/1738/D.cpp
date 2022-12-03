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
int deg[N];
vector<int> v[N];
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
		int l = 0, r = n;
		fill(deg, deg + n + 1, 0);
		for (int i = 1; i <= n; i++)
			v[i].clear();
		for (int i = 1; i <= n; i++)
		{
			int val;
			scanf("%d", &val);
			if (val >= 1 && val <= n)
			{
				v[val].push_back(i);
				deg[i]++;
			}
			if (val < i) r = min(r, i - 1);
			else l = max(l, i);
		}
		int k = r;
		printf("%d\n", k);
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			int sz = q.size();
			while (sz--)
			{
				int x = q.front();
				q.pop();
				if (v[x].empty())
				{
					printf("%d ", x);
				}
				else
				{
					q.push(x);
				}
			}
			if (q.empty()) break;
			int x = q.front();
			q.pop();
			printf("%d ", x);
			for (auto& y : v[x])
			{
				if (deg[y] -- == 1)
					q.push(y);
			}
		}
		puts("");
	}
	return 0;
}