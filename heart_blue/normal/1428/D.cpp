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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	int cnt0 = count(a + 1, a + n + 1, 0);
	if (cnt0 == n)
	{
		puts("0");
		return 0;
	}
	int cur = 1;
	vector<pair<int, int>> ans;
	stack<int> s;
	int last3 = 0;
	int last2 = 0;
	int last1 = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 3)
		{
			if (cnt == 0) ans.emplace_back(cur, i);
			else
			{
				ans.emplace_back(cur, i);
				ans.emplace_back(cur + 1, i);
				cur++;
			}
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 3) last3 = i;
		if (a[i] == 2) last2 = i;
		if (a[i] == 1) last1 = i;
	}
	if (last1 == 0)
	{
		puts("-1");
		return 0;
	}
	if (last2 != 0 && last2 > last1)
	{
		puts("-1");
		return 0;
	}
	if (last3 != 0 && last3 > last1)
	{
		puts("-1");
		return 0;
	}
	if (last3 > 0)
	{
		if (last3 < last2)
		{
			ans.emplace_back(cur, last2);
			ans.emplace_back(cur + 1, last2);
			ans.emplace_back(cur + 1, last1);
			cur += 2;
			a[last1] = a[last2] = a[last3] = 0;
		}
		else
		{
			ans.emplace_back(cur, last1);
			ans.emplace_back(cur + 1, last1);
			cur += 2;
			a[last1] = a[last3] = 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 2) s.push(i);
		else if (a[i] == 1 && !s.empty())
		{
			int x = s.top();
			s.pop();
			a[i] = 0;
			ans.emplace_back(cur, x);
			ans.emplace_back(cur, i);
			cur++;
		}
	}
	if (!s.empty())
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 1)
		{
			ans.emplace_back(cur, i);
			cur++;
		}
	}
	if (ans.back().first > n)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}