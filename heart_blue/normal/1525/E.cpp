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
const LL mod = 998244353;
vector<int> v[N];
LL powmod(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	LL tot = 1;
	for (int i = 1; i <= n; i++)
	{
		tot = tot * i % mod;
		for (int j = 1; j <= m; j++)
		{
			int x;
			scanf("%d", &x);
			v[j].push_back(x);
		}
	}
	LL ans = 0;
	for (int i = 1; i <= m; i++)
	{
		sort(v[i].begin(), v[i].end());
		LL cur = 1;
		for (int j = 0; j < n; j++)
		{
			cur = cur * (v[i][j] - j - 1) % mod;
		}
		ans += tot - cur;
	}
	ans %= mod;
	ans = ans * powmod(tot, mod - 2) % mod;
	if (ans < 0) ans += mod;
	printf("%lld\n", ans);
	return 0;

}