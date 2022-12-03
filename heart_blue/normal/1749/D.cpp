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
const LL mod = 998244353;
LL gettot(LL n, LL m)
{
	m %= mod;
	LL o = 1;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		o = o * m % mod;
		ans += o;
	}
	return ans;
}
bool check(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL m;
	LL key = 1;
	cin >> n >> m;
	LL cur = 1;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (check(i)) 
			key = lcm(key, i);
		if (key > m)
			break;
		cur = cur * (m / key % mod) % mod;
		ans += cur;
	}
	ans = gettot(n, m) - ans;
	ans %= mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}