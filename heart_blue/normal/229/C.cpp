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
const int N = 1e6 + 10;
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	LL ans = 1LL * n * (n - 1) * (n - 2) / 6;
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		deg[x]++;
		deg[y]++;
	}
	LL tot = 0;
	for (int i = 1; i <= n; i++)
	{
		tot += 1LL * deg[i] * (n - deg[i] - 1);
	}
	printf("%lld\n", ans - tot / 2);
	return 0;
}