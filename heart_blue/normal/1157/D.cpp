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
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	if (n < 1LL * k*(k + 1) / 2)
	{
		puts("NO");
		return 0;
	}
	n -= k * (k + 1) / 2;
	for (int i = 1; i <= k; i++) a[i] = i + n / k;
	n %= k;
	a[k + 1] = INF;
	a[0] = INF;
	while (n)
	{
		int flag = 0;
		for (int i = k; i >= 1 && n > 0; i--)
		{
			int o = min(2 * a[i - 1] - a[i], a[i + 1] - a[i] - 1);
			o = min(o, n);
			n -= o;
			a[i] += o;
			flag |= o;
		}
		if (flag == 0) break;
	}
	if (n)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 1; i <= k; i++) printf("%d ", a[i]);
	return 0;
}