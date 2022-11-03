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
vector<LL> v;
void solve(LL cur)
{
	auto iter = lower_bound(v.begin(), v.end(), cur);
	LL ans = 4 * INF * INF;
	if (iter != v.end())
	{
		ans = min(ans, abs(cur - *iter));
	}
	if (iter != v.begin())
	{
		iter--;
		ans = min(ans, abs(cur - *iter));
	}
	printf("%lld\n", ans);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if (i % 2 == 0) a[i] *= -1;
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld", &b[i]);
		if (i % 2 == 0) b[i] *= -1;
		b[i] += b[i - 1];
	}
	for (int i = n; i <= m; i++)
	{
		LL sum = b[i] - b[i - n];
		if ((i - n) % 2 == 1) sum *= -1;
		v.push_back(sum);
	}
	sort(v.begin(), v.end());
	LL cur = a[n];
	solve(cur);
	while (q--)
	{
		int l, r;
		LL x;
		scanf("%d%d%lld", &l, &r, &x);
		if ((r - l) % 2 == 0)
		{
			if (l & 1) cur += x;
			else cur -= x;
		}
		solve(cur);
	}
	return 0;
}