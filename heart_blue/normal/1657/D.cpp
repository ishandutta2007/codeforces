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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
LL a[N];
// H/d < h/D

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, C;
	scanf("%d%d", &n, &C);
	for (int i = 1; i <= n; i++)
	{
		int c, d, h;
		scanf("%d%d%d", &c, &d, &h);
		a[c] = max(a[c], 1LL * d * h);
	}
	for (int i = C; i >= 1; i--)
	{
		for (int j = i; j <= C; j += i)
			a[j] = max(a[j], a[i] * (j / i));
	}
	for (int i = 2; i <= C; i++)
		a[i] = max(a[i], a[i - 1]);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		LL d, h;
		scanf("%lld%lld", &d, &h);
		int pos = upper_bound(a + 1, a + C + 1, 1LL * d * h) - a;
		if (pos > C) pos = -1;
		printf("%d ", pos);
	}
	return 0;
}