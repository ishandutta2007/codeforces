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
const int N = 1e5 + 10;
pair<LL, LL> a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &a[i].second, &a[i].first);
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	LL ans = 0;
	LL cur = 0;
	while (l <= r)
	{
		while (cur < a[l].first && l <= r)
		{
			LL o = min(a[l].first - cur, a[r].second);
			cur += o;
			a[r].second -= o;
			ans += o * 2;
			if (a[r].second == 0) r--;
		}
		if (l > r) break;
		ans += a[l].second;
		cur += a[l].second;
		l++;
	}
	printf("%lld\n", ans);
	return 0;
}