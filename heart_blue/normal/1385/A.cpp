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
bool solve(int x, int y, int z)
{
	map<int, int> mc;
	mc[x]++, mc[y]++, mc[z]++;
	if (mc.size() == 3) return false;
	if (mc.begin()->second == 2) return false;
	int a, b, c;
	if (x == y) a = x, b = c = z;
	if (x == z) b = z, a = c = y;
	if (y == z) c = y, a = b = x;
	puts("YES");
	printf("%d %d %d\n", a, b, c);
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
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (!solve(x, y, z)) puts("NO");
	}
	return 0;
}