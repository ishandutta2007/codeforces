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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
const int mod = 1e9 + 9;
bool check(int n, int m, int k)
{
	int blank = m / (k - 1);
	if (m % (k - 1) == 0) blank--;
	return n >= m + blank;
}
LL pow2(int b)
{
	LL o = 2;
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * o % mod;
		o = o*o%mod;
		b >>= 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int l = 0, r = m / k;
	int ret = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(n - mid*k, m - mid*k, k)) ret = mid, r = mid - 1;
		else l = mid + 1;
	}
	LL pre = 0;
	LL ans = 0;
	for (int i = 1; i <= ret; i++)
	{
		pre = (pre + k) * 2;
		pre %= mod;
	}
	//f[i] = (f[i - 1] + k) * 2;
	//f[i] + 2 * k = (f[i - 1] + 2 * k) * 2;
	ans = (pow2(ret) - 1) * 2 * k%mod;
	ans += m - ret*k;
	ans %= mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}