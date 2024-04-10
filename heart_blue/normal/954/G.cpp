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
const int N = 5e5 + 10;
LL a[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, len;
	LL k;
	scanf("%d%d%lld", &n, &len, &k);
	for (int i = 1; i <= n; i++)
	{
		int l = max(i - len, 1);
		int r = min(n + 1, i + len + 1);
		int x;
		scanf("%d", &x);
		a[l] += x;
		a[r] -= x;
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] += a[i - 1];
	}
	len = len * 2 + 1;
	LL ans = 0;
	LL l = 0, r = 4 * INF * INF;
	while (l <= r)
	{
		LL mid = l + (r - l) / 2;
		LL rest = k;
		fill(sum + 1, sum + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			sum[i] += sum[i - 1];
			LL o = max(0LL, mid - (sum[i] + a[i]));
			if (o > rest)
			{
				rest = -1;
				break;
			}
			rest -= o;
			sum[i] += o;
			sum[min(n + 1, i + len)] -= o;
		}
		if (rest >= 0) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}