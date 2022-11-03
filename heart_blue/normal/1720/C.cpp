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
const int N = 5e2 + 10;
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
			cnt += count(str[i], str[i] + m, '1');
		}
		int minv = 4;
		for (int i = 0; i + 1 < n; i++)
		{
			for (int j = 0; j + 1 < m; j++)
			{
				int sum = 0;
				for (int o1 = 0; o1 < 2; o1++)
				{
					for (int o2 = 0; o2 < 2; o2++)
					{
						sum += str[i + o1][j + o2] - '0';
					}
				}
				minv = min(sum, minv);
			}
		}
		int ans = 0;
		if (minv > 0)
		{
			ans++;
			cnt -= max(1, minv - 1);
		}
		printf("%d\n", ans + cnt);
	}
	return 0;
}