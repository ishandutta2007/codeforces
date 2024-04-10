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
int sz[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b * b == a * c && c * c == b * d)
	{
		if (d * d % c) puts("42");
		else printf("%d\n", d * d / c);
		return 0;
	}
	if (2 * b == a + c && 2 * c == b + d)
	{
		printf("%d\n", 2 * d - c);
		return 0;
	}
	puts("42");
	return 0;
}