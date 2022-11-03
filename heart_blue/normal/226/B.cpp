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
const int N = 2e5 + 10;
int a[N];
LL sum[N];
LL ans[N];
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
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = a[i] + sum[i - 1];
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x;
		scanf("%d", &x);
		if (ans[x] != 0)
		{
			printf("%lld ", ans[x]);
			continue;
		}
		int l = n, r = n;
		int o = 0;
		LL& res = ans[x];
		while (r > 0)
		{
			res += (sum[r] - sum[l - 1]) * o;
			o++;
			tie(l, r) = make_pair((int)max(0LL, l - (r - l + 1) * 1LL * x), l - 1);
		}
		printf("%lld ", res);
	}
	return 0;
}