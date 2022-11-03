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
const int N = 1e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL sum[2] = { 0,0 };
		int cnt[2] = { 0,0 };
		int n, q;
		scanf("%d%d", &n, &q);
		while (n--)
		{
			int x;
			scanf("%d", &x);
			sum[x & 1] += x;
			cnt[x & 1] ++;
		}
		while (q--)
		{
			int op, x;
			scanf("%d%d", &op, &x);
			if (x % 2 == 0)
			{
				sum[op] += 1LL * cnt[op] * x;
			}
			else
			{
				cnt[op ^ 1] += cnt[op];
				sum[op ^ 1] += 1LL * cnt[op] * x + sum[op];
				cnt[op] = 0;
				sum[op] = 0;
			}
			printf("%lld\n", sum[0] + sum[1]);
		}
	}
	return 0;
}