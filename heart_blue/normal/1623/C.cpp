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
LL a[N];
LL b[N];
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
			scanf("%lld", &a[i]);
		}
		int l = 0, r = INF;
		int ans = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			fill(b + 1, b + n + 1, 0LL);
			int flag = 1;
			for (int i = n; i >= 1; i--)
			{
				if (b[i] + a[i] < mid)
				{
					flag = 0;
					break;
				}
				LL o = min(a[i], b[i] + a[i] - mid) / 3;
				if (i >= 3)
				{
					b[i - 1] += o;
					b[i - 2] += 2 * o;
				}
			}
			if (flag) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}