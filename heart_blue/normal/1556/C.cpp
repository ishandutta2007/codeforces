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
const int N = 3e3 + 10;
int a[N];
LL getlen(LL l1, LL r1, LL l2, LL r2)
{
	return max(0LL, min(r2, r1) - max(l1, l2) + 1);
}
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
	LL ans = 0;
	for (int i = 1; i <= n; i += 2)
	{
		LL l = 1, r = a[i];
		for (int j = i + 1; j <= n; j++)
		{
			if (j % 2 == 0)
			{
				ans += getlen(l, r, 1, a[j]);
				l -= a[j];
				r -= a[j];
				if (r < 0) break;
				l = max(0LL, l);
				r = max(0LL, r);
			}
			else
			{
				l += a[j];
				r += a[j];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}