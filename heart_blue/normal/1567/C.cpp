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
const int N = 1e3 + 10;
map<pair<int, int>, int> mc;
int dfs(int n, int o)
{
	if (n < o) return 0;
	if (n == 0 && o == 0) return 1;
	if (mc.count({ n,o })) return mc[{n, o}];
	int& ret = mc[{n, o}] = 0;
	int c = o % 10;
	o /= 10;
	for (int i = 0; i < 10; i++)
	{
		int j = n % 10 - i - c;
		if (j >= 0) ret += dfs(n / 10, o);
		else ret += dfs(n / 10, o + 10);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", dfs(n, 0) - 2);
	}
	return 0;
}