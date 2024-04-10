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
const int N = 3e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ans = m;
	int l = 0, r = m;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int pre = 0;
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			int x = a[i] + mid;
			if (x < m)
			{
				if (x < pre)
				{
					flag = 0;
					break;
				}
				pre = max(pre, a[i]);
			}
			else
			{
				x %= m;
				if (pre <= x) continue;
				pre = max(pre, a[i]);
			}
		}
		if (flag) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}