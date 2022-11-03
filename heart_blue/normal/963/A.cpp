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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
LL powmod(LL a, LL b, LL mod = INF)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		a = a * a%mod;
		b >>= 1;
	}
	return ret;
}
LL powsum(LL a, LL b, LL mod = INF)
{
	if (a == 1) return (b + 1) % mod;
	else return (powmod(a, b + 1) - 1)*powmod(a - 1, mod - 2) % mod;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, a, b, k;
	cin >> n >> a >> b >> k;
	string str;
	cin >> str;
	LL pre = powmod(a, n);
	a = powmod(a, INF - 2);
	a = a * b%INF;
	LL ans1 = 0;
	for (int i = 0; i < k; i++)
	{
		LL o = powmod(a, i);
		if (str[i] == '+') ans1 += o;
		else ans1 -= o;
		if (ans1 < 0) ans1 += INF;
		if (ans1 >= INF) ans1 -= INF;
	}
	int x = (n + 1) / k;
	LL o = powsum(powmod(a, k), x - 1);
	if (o < 0) o += INF;
	cout << o * pre%INF*ans1%INF;
	return 0;
}