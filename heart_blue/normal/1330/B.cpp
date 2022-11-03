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
int flag[N];
int flag1[N];
int flag2[N];
int a[N];
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
		memset(flag, 0, sizeof(int) * (n + 1));
		memset(flag1, 0, sizeof(int) * (n + 1));
		memset(flag2, 0, sizeof(int) * (n + 1));
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int maxv = 0;
		for (int i = 1; i <= n; i++)
		{
			if (flag[a[i]]) break;
			flag[a[i]] = 1;
			maxv = max(maxv, a[i]);
			if (maxv == i)
			{
				flag1[i] = 1;
			}
		}
		maxv = 0;
		memset(flag, 0, sizeof(int) * (n + 1));
		for (int i = n; i >= 1; i--)
		{
			if (flag[a[i]]) break;
			flag[a[i]] = 1;
			maxv = max(maxv, a[i]);
			if (maxv == n - i + 1)
			{
				flag2[i] = 1;
			}
		}
		vector<pair<int, int>> ans;
		for (int i = 1; i < n; i++)
		{
			if (flag1[i] && flag2[i + 1])
				ans.emplace_back(i, n - i);
		}
		printf("%d\n", ans.size());
		for (auto& p : ans)
			printf("%d %d\n", p.first, p.second);
	}
	return 0;
}