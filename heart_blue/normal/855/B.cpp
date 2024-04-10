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
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int lmax[N], rmax[N];
int lmin[N], rmin[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, p, q, r;
	cin >> n >> p >> q >> r;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			lmax[i] = lmin[i] = a[i];
		}
		else
		{
			lmax[i] = max(a[i], lmax[i - 1]);
			lmin[i] = min(a[i], lmin[i - 1]);
		}
	}
	for (int i = n; i > 0; i--)
	{
		if (i == n)
		{
			rmax[i] = rmin[i] = a[i];
		}
		else
		{
			rmax[i] = max(a[i], rmax[i + 1]);
			rmin[i] = min(a[i], rmin[i + 1]);
		}
	}
	LL ans = -INF*INF*4;
	for (int i = 1; i <= n; i++)
	{
		LL tmp = a[i] * q + max(lmax[i] * p, lmin[i] * p) + max(rmax[i] * r, rmin[i] * r);
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}