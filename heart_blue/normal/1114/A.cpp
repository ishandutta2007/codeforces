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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x, y, z;
	int a, b, c;
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	if (x > a)
	{
		puts("NO");
		return 0;
	}
	a -= x;
	if (y > a + b)
	{
		puts("NO");
		return 0;
	}
	c += a + b - y;
	if (z > c) puts("NO");
	else puts("YES");
	return 0;
}