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
const int N = 3e5 + 10;
int a[N];
int check(int i)
{
	int ret = 0;
	if (a[i - 1] > a[i]) ret += a[i - 1] - a[i];
	if (a[i] > a[i + 1]) ret += a[i] - a[i + 1];
	return ret;
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
		int q;
		scanf("%d%d", &n, &q);
		LL ans = 0;
		a[0] = -INF;
		LL maxv = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			maxv = max(1LL * a[i], maxv);
			ans += max(a[i - 1] - a[i], 0);
		}
		ans += a[n];
		a[n + 1] = 0;
		printf("%lld\n", max(ans, maxv));
		while (q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			ans -= check(l);
			ans -= check(r);
			swap(a[l], a[r]);
			ans += check(l);
			ans += check(r);
			printf("%lld\n", max(maxv, ans));
		}
	}
	return 0;
}