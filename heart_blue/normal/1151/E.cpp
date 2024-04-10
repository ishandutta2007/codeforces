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
		int x;
		scanf("%d", &x);
		ans += 1LL * x * (n - x + 1);
		a[i] = x;
	}
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int y = a[i + 1];
		if (x > y) swap(x, y);
		ans -= 1LL * x * (n - y + 1);
	}
	printf("%lld\n", ans);
	return 0;
}