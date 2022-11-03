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
const int N = 2e2 + 10;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		map<int, int> mc1, mc2;
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int x;
				scanf("%d", &x);
				mc1[i + j] += x;
				mc2[i - j] += x;
				a[i][j] = x;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int sum = mc1[i + j] + mc2[i - j] - a[i][j];
				ans = max(ans, sum);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}