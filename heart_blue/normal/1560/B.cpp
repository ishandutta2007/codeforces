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
const int N = 1e5 + 10;
bool check(int x)
{
	if (x % 3 == 0 || x % 10 == 3) return false;
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int n = abs(a - b);
		if (max({ a,b,c }) > 2 * n)
		{
			puts("-1");
			continue;
		}
		if (c > n) printf("%d\n", c - n);
		else printf("%d\n", c + n);
	}
	return 0;
}