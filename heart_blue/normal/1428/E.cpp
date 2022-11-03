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
LL cal(int n, int x)
{
	if (n % x == 0)
	{
		int avg = n / x;
		return 1LL * avg * avg * x;
	}
	else
	{
		int avg = n / x;
		LL ret = 1LL * avg * avg * x;
		ret += 1LL * n % x * (2 * avg + 1);
		return ret;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	LL cur = 0;
	priority_queue<tuple<LL, int, int>> pq;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cur += 1LL * x * x;
		if (x != 1)
			pq.emplace(cal(x, 1) - cal(x, 2), x, 2);
	}
	while (n < k)
	{
		n++;
		LL tot;
		int x, o;
		tie(tot, x, o) = pq.top();
		pq.pop();
		cur -= tot;
		if (o < x)
			pq.emplace(cal(x, o) - cal(x, o + 1), x, o + 1);
	}
	printf("%lld\n", cur);
	return 0;
}