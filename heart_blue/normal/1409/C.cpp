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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		int ans = INF, d = -1;
		for (int i = 1; i <= 50; i++)
		{
			if ((y - x) % i) continue;
			if ((y - x) / i + 1 > n) continue;
			int l = (y + i - 1) / i;
			if (ans > y + max(0, n - l) * i)
			{
				ans = y + max(0, n - l) * i;
				d = i;
			}
		}
		for (int i = 0; i < n; i++)
		{
			printf("%d ", ans);
			ans -= d;
		}
		puts("");
	}
	return 0;
}