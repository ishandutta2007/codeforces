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
const int N = 1e5 + 10;
int ans[N];
tuple<int, int, int> vp[N];
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
			auto& [a, b, id] = vp[i];
			id = i;
			scanf("%d", &a);
		}
		for (int i = 1; i <= n; i++)
		{
			auto& [a, b, id] = vp[i];
			scanf("%d", &b);
		}
		sort(vp + 1, vp + n + 1);
		int minv = INF;
		int cur = INF;
		int low = n;
		for (int i = n; i >= 1; i--)
		{
			auto& [a, b, id] = vp[i];
			minv = min(minv, b);
			if (i == n)
			{
				cur = b;
				ans[id] = 1;
			}
			else
			{
				if (b >= cur)
					low = i, cur = min(cur, minv);
			}
		}
		fill(ans + 1, ans + n + 1, 0);
		for (int i = low; i <= n; i++)
		{
			auto& [a, b, id] = vp[i];
			ans[id] = 1;
		}
		for (int i = 1; i <= n; i++)
			printf("%d", ans[i]);
		puts("");
	}
	return 0;
}