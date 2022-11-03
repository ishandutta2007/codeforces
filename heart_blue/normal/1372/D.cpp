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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL l[N];
LL r[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (i & 1)
			ans += a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		l[i] = a[i];
		if (i >= 2) l[i] += l[i - 2];
	}
	for (int i = n; i >= 1; i--)
	{
		r[i] = a[i] + r[i + 2];
	}
	for (int i = 1; i < n; i++)
	{
		ans = max(ans, l[i] + r[i + 1]);
	}
	printf("%lld\n", ans);
	return 0;

}