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
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e2 + 10;
const LL INF = 1e9 + 7;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a <= b)
		{
			printf("%d\n", b);
			continue;
		}
		if (c <= d)
		{
			puts("-1");
			continue;
		}
		printf("%lld\n", 1LL * (a - b + (c - d) - 1) / (c - d) * c + b);
	}
	return 0;
}