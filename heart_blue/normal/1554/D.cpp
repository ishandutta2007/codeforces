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
LL a[N];
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		if (n < 26)
		{
			for (int i = 0; i < n; i++)
			{
				putchar(i + 'a');
			}
			puts("");
			continue;
		}
		if (n % 2 == 0)
		{
			for (int i = 0; i < n / 2; i++) putchar('a');
			putchar('b');
			for (int i = 1; i < n / 2; i++) putchar('a');
			puts("");
		}
		else
		{
			n--;
			for (int i = 0; i < n / 2; i++) putchar('a');
			putchar('b');
			putchar('c');
			for (int i = 1; i < n / 2; i++) putchar('a');
			puts("");
		}
	}
	return 0;
}