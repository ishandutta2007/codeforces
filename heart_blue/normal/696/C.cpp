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
const int N = 5E3 + 10;
LL powmod(LL a, LL b, LL mod = INF)
{
	a = (a + mod) % mod;
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a%mod;
		a = a * a%mod;
		b >>= 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
/*
1		0		0
0		0.5		0.5
0.5		0.25	0.25
0.25	0.375	0.375
0.375	
f(n) = (1-f(n-1))/2
	*/
	int rev3 = 333333336;
	LL ans = 2;
	int n;
	cin >> n;
	int o = -1;
	for (int i = 1; i <= n; i++)
	{
		LL x;
		cin >> x;
		if (x % 2 == 0) o = 1;
		ans = powmod(ans, x);
	}
	ans = ans * powmod(2, INF - 2) % INF;
	printf("%lld/%lld", (ans + o)*rev3 % INF, ans);
	return 0;
}