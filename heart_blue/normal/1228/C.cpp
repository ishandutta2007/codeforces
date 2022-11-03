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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
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
LL solve(int x, LL n)
{
	LL cur = 1;
	vector<LL> v;
	while (cur <= n / x)
	{
		cur *= x;
		v.push_back(n / cur);
	}
	for (int i = 0; i + 1 < v.size(); i++)
	{
		v[i] -= v[i + 1];
	}
	LL ans = 1;
	cur = x;
	for (int i = 0; i < v.size(); i++)
	{
		ans = ans * powmod(cur, v[i]) % INF;
		cur = cur * x % INF;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL x, n;
	LL ans = 1;
	cin >> x >> n;
	for (LL i = 2; i * i <= x; i++)
	{
		if (x % i) continue;
		ans = ans * solve(i, n) % INF;
		while (x % i == 0)
			x /= i;
	}
	if (x > 1)
		ans = ans * solve(x, n) % INF;
	cout << ans << endl;
	return 0;
}