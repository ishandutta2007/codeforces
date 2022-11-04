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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int sum[2][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int o = 0; o < 2; o++)
		{
			for (int i = 1; i <= n; i++)
			{
				scanf("%d", &sum[o][i]);
				sum[o][i] += sum[o][i - 1];
			}
		}
		int ans = 2 * INF;
		for (int i = 1; i <= n; i++)
		{
			ans = min(ans, max(sum[1][i - 1], sum[0][n] - sum[0][i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}