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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL sum(LL n)
{
	return n*(n + 1) / 2;
}
LL sum(LL n, LL m)
{
	if (m > n) m = n;
	return sum(n) - sum(n - m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	m -= n;
	LL l = 1, r = m;
	LL ret = 0;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		LL cost = sum(mid, k);
		cost += sum(mid, n - k + 1);
		cost -= mid;
		if (cost <= m) ret = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ret + 1 << endl;
	return 0;
}