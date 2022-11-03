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
const int N = 1e5 + 10;
pair<int, int> b[N];
int a[N];
LL sum[N];
int res[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL A, cf, cm;
	LL m;
	cin >> n >> A >> cf >> cm;
	cin >> m;
	for (int i = 1; i <= n; i++) cin >> b[i].first, b[i].second = i;
	sort(b + 1, b + n + 1);
	for (int i = 0; i <= n; i++) a[i] = b[i].first;
	for (int i = 1; i <= n; i++) sum[i] = a[i] + sum[i - 1];
	LL ans = 0;
	pair<int, int> k = { 0,n };
	for (int i = n; i >= 0; i--)
	{
		int l = a[1], r = A;
		int key = l;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			LL o = lower_bound(a + 1, a + n + 1, mid) - a - 1;
			if (mid*o - sum[o] <= m) key = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (ans < (n - i)*cf + key * cm)
		{
			ans = (n - i)*cf + key*cm;
			k = { key,i };
		}
		if (m >= A - a[i])
		{
			m -= A - a[i];
			a[i] = A;
		}
		else break;
	}
	for (int i = 1; i <= n; i++)
	{
		b[i].first = max(b[i].first, k.first);
		if (i > k.second) b[i].first = A;
		res[b[i].second] = b[i].first;
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", res[i]);
	}
	return 0;
}