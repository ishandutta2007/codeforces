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
const int N = 1e6 + 10;
int check(int sum)
{
	int n = sqrt(sum * 2);
	if (n*(n + 1) / 2 == sum) return n + 1;
	else return -1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a + b + c + d == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	int cnt0 = check(a);
	int cnt1 = check(d);
	if (b + c == 0)
	{
		if (cnt0 == 1) cnt0 = 0;
		if (cnt1 == 1) cnt1 = 0;
	}
	if (cnt0 == -1 || cnt1 == -1)
	{
		puts("Impossible");
		return 0;
	}
	LL n = cnt0 + cnt1;
	if (n*(n - 1) / 2 != a + b + c + d)
	{
		puts("Impossible");
		return 0;
	}
	if (cnt0 == n)
	{
		while (cnt0--) putchar('0');
		return 0;
	}
	if (cnt1 == n)
	{
		while (cnt1--) putchar('1');
		return 0;
	}
	int c0 = 0, c1 = 0;
	while (b + c > cnt1)
	{
		if (b > c) b -= cnt1, c0++;
		else c -= cnt1, c1++;
	}
	while (c0--) putchar('0');
	while (c--) putchar('1');
	putchar('0');
	while (b--) putchar('1');
	while (c1--) putchar('0');
	return 0;
}