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
LL lsum[N];
LL lval[N];
LL rsum[N];
LL rval[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(a, 0);
	MEM(rsum, 0);
	MEM(rval, 0);
	MEM(lsum, 0);
	MEM(rval, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		lsum[i] = lsum[i - 1];
		lval[i] = a[i];
		if (lval[i] <= lval[i - 1])
		{
			lsum[i] += lval[i - 1] - lval[i] + 1;
			lval[i] = lval[i - 1] + 1;
		}
	}
	for (int i = n; i > 0; i--)
	{
		rsum[i] = rsum[i + 1];
		rval[i] = a[i];
		if (rval[i] <= rval[i + 1])
		{
			rsum[i] += rval[i + 1] - rval[i] + 1;
			rval[i] = rval[i + 1] + 1;
		}
	}
	LL ans = min(rsum[1], lsum[n]);
	for (int i = 1; i < n; i++)
	{
		if (lval[i] <= rval[i + 1])
		{
			ans = min(ans, rval[i + 1] - lval[i] + 1 + lsum[i] + rsum[i + 1]);
		}
		else ans = min(ans, lsum[i] + rsum[i + 1]);
	}
	cout << ans << endl;
	return 0;
}