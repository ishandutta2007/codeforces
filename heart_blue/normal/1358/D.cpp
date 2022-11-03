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
const int N = 4e5 + 10;
int a[N];
LL sum(int n)
{
	return 1LL * n * (n + 1) / 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL x;
	scanf("%d%lld", &n, &x);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	LL tot = 0;
	LL ans = 0;
	int ptr = 1;
	LL cur = 0;
	for (int i = 1; i <= n; i++)
	{
		ptr = max(ptr, i);
		while (tot + a[ptr] < x)
		{
			tot += a[ptr];
			cur += sum(a[ptr++]);
		}
		int last = x - tot;
		if (ptr > i)
		{
			int rest = min(a[i], a[ptr] - last);
			cur -= sum(a[i]);
			tot -= a[i];
			ans = max(ans, cur + sum(a[i]) - sum(rest) + sum(last + rest));
		}
		else
		{
			ans = max(ans, sum(a[i]) - sum(a[i] - last));
		}

	}
	printf("%lld\n", ans);
	return 0;
}