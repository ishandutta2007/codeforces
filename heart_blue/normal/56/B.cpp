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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memcpy(b, a, sizeof(b));
	sort(b + 1, b + n + 1);
	int l = n+1, r = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != b[i])
		{
			l = min(i, l);
			r = max(i, r);
		}
	}
	if (r == 0)
	{
		puts("0 0");
		return 0;
	}
	reverse(a + l, a + r + 1);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != b[i])
		{
			puts("0 0");
			return 0;
		}
	}
	printf("%d %d\n", l, r);
	return 0;
}