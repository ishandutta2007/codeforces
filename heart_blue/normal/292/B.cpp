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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n != m && n != m + 1)
	{
		puts("unknown topology");
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		deg[x]++;
		deg[y]++;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n == m && deg[i] != 2)
		{
			puts("unknown topology");
			return 0;
		}
		if (deg[i] == 1) cnt++;
	}
	if (n == m) puts("ring topology");
	else if (cnt == 2) puts("bus topology");
	else if (cnt == n - 1) puts("star topology");
	else puts("unknown topology");
	return 0;
}