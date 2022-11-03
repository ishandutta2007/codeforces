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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e4 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, a, b, x, y;
		scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &x, &y);
		int ans = 0;
		int ox = 1;
		int oy = 1;
		while (a != x && b != y)
		{
			ans++;
			if (a + ox > n) ox = -1;
			if (a + ox < 1) ox = 1;
			if (b + oy > m) oy = -1;
			if (b + oy < 1) oy = 1;
			a += ox;
			b += oy;
		}
		printf("%d\n", ans);
	}
	return 0;
}