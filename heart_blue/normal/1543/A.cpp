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
const int N = 2e5 + 10;
LL dis(int a, int b, int c, int d)
{
	return abs(c - a) + abs(d - b);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL a, b;
		scanf("%lld%lld", &a, &b);
		if (a < b) swap(a, b);
		if (a == b) puts("0 0");
		else
		{
			LL d = a - b;
			LL res = min(b % d, (d - b % d) % d);
			printf("%lld %lld\n", d, res);
		}
	}
	return 0;
}