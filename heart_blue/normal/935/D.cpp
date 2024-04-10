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
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a%mod;
	}
	return ret;
}
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tot = 0;
	LL n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i], tot += a[i] == 0;
	for (int i = 0; i < n; i++) cin >> b[i], tot += b[i] == 0;
	LL q = powmod(powmod(m, tot), INF - 2);
	LL ans = 0;
	LL o = 1;
	for (int i = 0; i < n; i++)
	{
		tot -= a[i] == 0;
		tot -= b[i] == 0;
		LL r = o*powmod(m, tot)%INF;
		if (a[i] == 0 && b[i] == 0)
		{
			ans += m*(m-1)/2 % INF*r%INF;
			o = o * m%INF;
		}
		else if (a[i] == 0)
		{
			ans += (m - b[i])*r%INF;
		}
		else if (b[i] == 0)
		{
			ans += (a[i] - 1)*r%INF;
		}
		else
		{
			if (a[i] < b[i]) break;
			if (a[i] > b[i])
			{
				ans += r;
				if (ans >= INF) ans -= INF;
				break;
			}
		}
		if (ans >= INF) ans -= INF;
	}
	cout << ans * q %INF << endl;
	return 0;
}