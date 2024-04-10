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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int a[N];
int b[N];
int solve(int n, int o)
{
	int rest = n * 2;
	int ans = 0;
	memcpy(a, b, sizeof(a));
	while (a[1] != 1 && rest > 0)
	{
		rest--;
		ans++;
		int pos = find(a + 1, a + n + 1, 1) - a;
		if (pos % 2 == o)
		{
			for (int i = 1; i <= n; i += 2)
			{
				swap(a[i], a[i + 1]);
			}
		}
		else
		{
			for (int i = 1; i <= n / 2; i++)
			{
				swap(a[i], a[i + n / 2]);
			}
		}
	}
	if (is_sorted(a + 1, a + n + 1)) return ans;
	else return INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	n *= 2;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
	}
	int ans = min(solve(n, 0), solve(n, 1));
	if (ans == INF)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}