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
const int N = 1e6 + 10;
int check(int a, int b, int c)
{
	if (a == 0 && b == 0)
	{
		if (c == 0) return 2;
		else return 0;
	}
	else return 1;
}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a1, b1, c1;
	int a2, b2, c2;
	cin >> a1 >> b1 >> c1;
	cin >> a2 >> b2 >> c2;
	int cnt1 = check(a1, b1, c1);
	int cnt2 = check(a2, b2, c2);
	if (min(cnt1, cnt2) == 0)
	{
		puts("0");
		return 0;
	}
	if (max(cnt1, cnt2) == 2)
	{
		puts("-1");
		return 0;
	}
	if (a1 * b2 == a2 * b1)
	{
		if (a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1) puts("-1");
		else puts("0");
	}
	else puts("1");

	return 0;
}