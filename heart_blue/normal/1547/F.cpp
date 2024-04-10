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
const int N = 4e5 + 10;
int a[N];
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
			scanf("%d", &a[i]);
			a[i + n] = a[i];
		}
		int l = 1, r = n;
		int ans = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			stack<pair<int, int>> head, tail;
			head.emplace(0, 0);
			tail.emplace(0, 0);
			int pre = -1;
			for (int i = 1; i <= n * 2; i++)
			{
				tail.emplace(a[i], gcd(a[i], tail.top().second));
				if (i > mid)
				{
					if (head.size() == 1)
					{
						while (tail.size() > 1)
						{
							int g = gcd(head.top().second, tail.top().first);
							head.emplace(tail.top().first, g);
							tail.pop();
						}
					}
					head.pop();
				}
				if (i >= mid)
				{
					int g = gcd(head.top().second, tail.top().second);
					if (pre == -1) pre = g;
					if (pre != g)
					{
						pre = -1;
						break;
					}
				}
			}
			if (pre != -1) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}