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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	MEM(a, 0);
	a[0] = 1;
	while (n--)
	{
		int x;
		scanf("%d", &x);
		x %= m;
		if (x == 0 || a[m-x])
		{
			puts("YES");
			return 0;
		}
		for (int i = m + x; i >= x; i--)
		{
			a[i] |= a[i - x];
		}
		for (int i = m + x; i >= m; i--)
		{
			a[i - m] |= a[i];
		}
	}
	puts("NO");
	return 0;
}