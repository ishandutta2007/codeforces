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
const int N = 5e2 + 10;
LL solve(LL a, LL b, LL n)
{
	n %= INF;
	int inv2 = (INF + 1) / 2;
	return (a + b) % INF * n % INF * inv2 % INF;
}
LL getans(LL n)
{
	LL sum[2] = { 0LL,0LL };
	int o = 0;
	LL cur = 1;
	while (n)
	{
		o ^= 1;
		LL x = min(n, cur);
		sum[o] += x;
		n -= x;
		cur <<= 1;
	}
	return solve(1, 2 * sum[1] - 1, sum[1]) + solve(2, sum[0] * 2, sum[0]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL l, r;
	cin >> l >> r;
	LL ans = getans(r) - getans(l - 1);
	ans %= INF;
	if (ans < 0) ans += INF;
	cout << ans << endl;
	return 0;
}