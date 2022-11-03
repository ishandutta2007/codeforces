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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e2 + 10;
int check(int &n, int s = 2)
{
	int ret = 1;
	for (int i = s; i * i <= n; i++)
	{
		if (n % i) continue;
		ret = i;
		break;
	}
	n /= ret;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		int a = check(n);
		if (a == 1 || n == 1)
		{
			puts("NO");
			continue;
		}
		int b = check(n, a + 1);
		if (b == 1 || n == 1 || b == n || a == n || a == b)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%d %d %d\n", a, b, n);
	}
	return 0;
}