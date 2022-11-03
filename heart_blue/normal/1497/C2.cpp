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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
void solve(int n)
{
	if (n % 4 == 0)
	{
		printf("%d %d %d\n", n / 4, n / 4, n / 2);
		return;
	}
	int a, b, c;
	a = n / 2, b = n / 2;
	c = n & 1;
	if (c == 0)
	{
		while (1)
		{
			c += 2;
			a--, b--;
			int lcm = c / gcd(c, a) * a;
			if (lcm * 2 <= n) break;
		}
	}
	printf("%d %d %d\n", a, b, c);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		while (k > 3) printf("1 "), k--, n--;
		solve(n);
	}
	return 0;
}