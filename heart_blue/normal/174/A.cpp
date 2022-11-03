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
const int N = 3e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, b;
	cin >> n >> b;
	int maxv = 0;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxv = max(maxv, a[i]);
		tot += a[i];
	}
	b -= maxv * n - tot;
	if (b < 0) puts("-1"), exit(0);
	for (int i = 1; i <= n; i++)
		printf("%.15f\n", 1.0 * b / n + maxv - a[i]);
	return 0;
}