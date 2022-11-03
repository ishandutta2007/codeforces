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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
list<int> l[N];
deque<int> q;
vector<int> ans;
int a[N];
int solve(int i)
{
	int j = q.front();
	q.pop_front();
	if (i == j)
	{
		return 0;
	}
	if (i == 0)
	{
		q.push_back(j);
		return j;
	}
	int x = a[l[i].back()];
	int y = a[l[j].front()];
	if (gcd(x, y) == 1)
	{
		ans.push_back(l[j].front());
		l[j].pop_front();
		if (!l[j].empty())
		{
			q.push_back(j);
			return j;
		}
		return 0;
	}
	else
	{
		for (auto& x : l[j])
			l[i].push_back(x);
		return i;
	}

}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
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
		for (int i = 1; i <= n; i++)
		{
			l[i].clear();
			int x;
			scanf("%d", &x);
			a[i] = x;
			l[i].push_back(i);
		}
		ans.clear();
		q.clear();
		for (int i = 1; i <= n; i++)
			q.push_back(i);
		int o = 0;
		while (q.size() > 1)
		{
			o = solve(o);
		}
		int x = q.front();
		auto& li = l[x];
		while (!li.empty())
		{
			int y = li.back();
			int x = li.front();
			if (gcd(a[x], a[y]) == 1)
			{
				ans.push_back(x);
				li.pop_front();
			}
			else
				break;
		}
		printf("%d", ans.size());
		for (auto& x : ans)
			printf(" %d", x);
		puts("");
	}
	return 0;
}