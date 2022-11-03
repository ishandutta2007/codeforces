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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a = 0, b = 0, c = 0, d = 0;
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (x > 0) a = max(x, a);
			if (x < 0) b = max(-x, b);
			if (y > 0) c = max(y, c);
			if (y < 0) d = max(-y, d);
		}
		printf("%d\n", (a + b + c + d) * 2);
	}
	return 0;
}