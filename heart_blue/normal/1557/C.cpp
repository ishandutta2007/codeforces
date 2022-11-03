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
LL powmod(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % INF;
		b >>= 1;
		a = a * a % INF;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		LL o = 1;
		LL ans = 0;
		for (int i = k - 1; i >= 0; i--)
		{
			if (n % 2 == 0)
			{
				ans += o * powmod(2, 1LL * i * n) % INF;
			}
			LL key = powmod(2, n - 1);
			if (n % 2 == 1)
				key++;
			else
				key--;
			o = key * o % INF;
		}
		ans += o;
		ans %= INF;
		if (ans < 0)
			ans += INF;
		printf("%lld\n", ans);
	}
	return 0;
}