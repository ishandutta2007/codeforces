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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int a, b, c, d;
	a = b = c = d = -INF;
	scanf("%d", &n);
	while (n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a = max(x + y, a);
		b = max(x - y, b);
		c = max(-x + y, c);
		d = max(-x - y, d);
	}
	printf("%d\n", a + b + c + d + 4);
	return 0;
}