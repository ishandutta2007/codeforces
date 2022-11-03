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
LL powmod(LL a, LL b, const LL mod = INF)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x, y;
	scanf("%d%d", &x, &y);
	if (y % x)
	{
		puts("0");
		return 0;
	}
	int n = y / x;
	vector<int> v;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i) continue;
		v.push_back(i);
		while (n % i == 0) n /= i;
	}
	if (n > 1) v.push_back(n);
	int tot = 1 << v.size();
	LL ans = 0;
	for (int o = 0; o < tot; o++)
	{
		int d = 1;
		int flag = 1;
		for (int i = 0; i < v.size(); i++)
		{
			if (o >> i & 1)
				d *= v[i], flag = -flag;
		}
		d = y / x / d;
		ans += flag * powmod(2, d - 1);
	}
	ans %= INF;
	if (ans < 0)
		ans += INF;
	printf("%lld\n", ans);
	return 0;
}