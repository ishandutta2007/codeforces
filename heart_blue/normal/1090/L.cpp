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
const int N = 5e2 + 10;
bool check(LL n, LL a, LL b, LL k, LL x)
{
	a = min(a, x);
	b = min(b, x);
	int len1 = n - n / 2;
	int len2 = n / 2;
	return k * x <= a * len1 + b * len2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, n, a, b, k;
	cin >> t >> n >> a >> b >> k;
	int l = 1, r = t;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(n, a, b, k, mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}