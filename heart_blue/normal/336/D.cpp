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
const int N = 2e5 + 10;
LL fact[N];
LL rfact[N];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % INF;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++) rfact[i] = (INF - INF / i) * rfact[INF % i] % INF;
	for (int i = 2; i < N; i++) rfact[i] = rfact[i] * rfact[i - 1] % INF;
}
LL C(int n, int m)
{
	return fact[n] * rfact[m] % INF * rfact[n - m];
}
LL solve(int o, int n, int m)
{
	if (n < 0 || m < 0) return 0;
	if (o == -1) return C(n + m, m);
	if (n + m == 1)
	{
		if (n == 1) return o == 0;
		else return o == 1;
	}
	LL ans = 0;
	if (o == 0)
	{
		ans += solve(1, n - 1, m);
		ans += solve(-1, n, m - 1);
	}
	else
	{
		ans += solve(0, n - 1, m);
	}
	return ans %= INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, m, g;
	scanf("%d%d%d", &n, &m, &g);
	LL ans = solve(g, n, m) % INF;
	if (ans < 0) ans += INF;
	printf("%lld\n", ans);
	return 0;
}