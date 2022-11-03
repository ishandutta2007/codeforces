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
const int N = 2e5 + 10;
LL powmod(LL a, LL b, LL mod = INF)
{
	if (a < 0) a += mod;
	LL ret = 1;
	LL o = a;
	while (b)
	{
		if (b & 1) ret = ret * o % mod;
		b >>= 1;
		o = o*o%mod;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	/*
	x
	ax+b
	aax+ab+b
	aaax+aab+ab+b
	aaaax+aaab+aab+ab+b
	*/
	LL a, b, n, x;
	cin >> a >> b >> n >> x;
	LL ans = 0;
	if (a == 1)
	{
		ans = (x + n%INF*b) % INF;
	}
	else
	{
		ans = x*powmod(a, n) % INF + powmod(a - 1, INF - 2)*(powmod(a, n) - 1) % INF*b%INF;
		ans %= INF;
		if (ans < 0) ans += INF;
	}
	cout << ans << endl;
	return 0;
}