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
const int N = 1e6 + 10;
int a[N];
LL sum[N];
LL solve(int n, int x)
{
	for (int i = 1; i <= n; i++)
	{
		a[i] = INF - a[i];
	}
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	LL minv = INF * INF;
	LL lsum = 0;
	for (int i = 1; i <= n; i++)
	{
		lsum += a[i];
		LL tot = 1LL * a[i] * i - lsum;
		int pos = upper_bound(a + 1, a + n + 1, a[i] + x) - a;
		tot += sum[n] - sum[pos - 1] - (n - pos + 1LL) * (a[i] + x);
		minv = min(minv, tot);
	}
	return minv;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL k;
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int l = 0, r = INF;
	int ans = INF;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		LL tot = min(solve(n, mid), solve(n, mid));
		if (tot <= k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}