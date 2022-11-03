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
const int N = 1e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	MEM(a, 0);
	for (int i = 1; i <= n; i++)
	{
		int o = 0;
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			o |= x << j;
		}
		a[o]++;
	}
	int tot = 1 << k;
	for (int i = 0; i < tot; i++)
	{
		for (int j = 0; j < tot; j++)
		{
			if (a[i] > 0 && a[j] > 0)
			{
				if ((i&j) == 0)
				{
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}