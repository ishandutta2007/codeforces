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
const int N = 1e6 + 10;
int flag[N];
int sum[N];
void solve()
{
	int n, c;
	scanf("%d%d", &n, &c);
	fill(sum, sum + c + 1, 0);
	fill(flag, flag + c + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		flag[x] = 1;
		sum[x]++;
	}
	for (int i = 1; i <= c; i++)
		sum[i] += sum[i - 1];
	if (flag[1] == 0)
	{
		puts("No");
		return;
	}
	for (int i = 2; i <= c; i++)
	{
		if (!flag[i]) continue;
		for (int j = i * 2; j <= c; j += i)
		{
			if (flag[j / i]) continue;
			if (sum[min(c, j + i - 1)] - sum[j - 1] > 0)
			{
				puts("No");
				return;
			}
		}
	}
	puts("Yes");
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		solve();
	}
	return 0;
}