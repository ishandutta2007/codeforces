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
const int N = 2e2 + 10;
LL f[N];
int sum(LL n)
{
	int ret = 0;
	while (n)
	{
		ret++;
		n >>= 1;
	}
	return ret;
}
LL solve(LL n, LL x)
{
	if (x == 0) return 0;
	int cnt = sum(n);
	if (cnt <= 1) return cnt;
	LL ret = 0;
	LL l = f[cnt - 1];
	if (x <= l)
	{
		ret = solve(n / 2, x);
	}
	else if (x == l + 1)
	{
		ret = n / 2 + n % 2;
	}
	else ret = n / 2 + n % 2 + solve(n / 2, x - (l + 1));
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	f[0] = 0;
	for (int i = 1; i < N; i++)
	{
		f[i] = 2 * f[i - 1] + 1;
	}
	LL n, l, r;
	cin >> n >> l >> r;
	cout << solve(n, r) - solve(n, l - 1) << endl;
	return 0;
}