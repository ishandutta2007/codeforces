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
const int N = 3e3 + 10;
LL powmod(LL a, LL b, LL mod = INF)
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
LL fact(int n)
{
	LL ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret = ret * i % INF;
	}
	return ret;
}
LL rfact(int n)
{
	return powmod(fact(n), INF - 2);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	LL ans = 2 * fact(2 * n - 1) * rfact(n - 1) % INF * rfact(n) - n;
	ans %= INF;
	if (ans < 0) ans += INF;
	cout << ans << endl;
	return 0;
}