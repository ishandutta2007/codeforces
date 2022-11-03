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
const int N = 3e7 + 10;
int flag[N];
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
bool check(int a, int b, int c)
{
	MEM(flag, 0);
	flag[0] = flag[1] = flag[2] = 1;
	int c1 = 0, c2 = 1, c3 = c;
	LL lcm = a / gcd(a, b)*b;
	lcm = lcm / gcd(lcm, c)*c;
	for (int i = 0; i <= lcm; i++)
	{
		if (flag[i] == 0) return false;
		if (c1 == i) c1 += a;
		if (c2 == i) c2 += b;
		if (c3 == i) c3 += c;
		flag[c1] = flag[c2] = flag[c3] = 1;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	if (a < b) swap(a, b);
	if (b < c) swap(b, c);
	if (a < b) swap(a, b);
	if (check(a, b, c) || check(a, c, b)) puts("YES");
	else puts("NO");
	return 0;
}