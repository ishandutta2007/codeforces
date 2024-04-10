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
int a[N];
int b[N];
pair<int, int> combine(int l1, int r1, int l2, int r2, int len)
{
	l1 = max(l1, 1);
	l2 = max(l2, 1);
	r1 = min(r1, len);
	r2 = min(r2, len);
	return { max(l1,l2),min(r1,r2) };
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
			scanf("%d%d", &a[i], &b[i]);
		}
		int l = 1, r = n;
		int ans = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			vector<pair<int, int>> vp;
			for (int i = 1; i <= n; i++)
			{
				vp.push_back(combine(mid - a[i], mid, 1, b[i] + 1, mid));
			}
			int cur = 1;
			for (int i = 0; i < n; i++)
			{
				auto [l, r] = vp[i];
				if (l <= cur && cur <= r)
				{
					cur++;
				}
			}
			if (cur > mid) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}