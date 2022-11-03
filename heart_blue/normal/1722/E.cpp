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
const int N = 1e3 + 10;
LL sum[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		MEM(sum, 0);
		while (n--)
		{
			int h, w;
			scanf("%d%d", &h, &w);
			sum[h][w] += h * w;
		}
		for (int i = 1; i <= 1000; i++)
		{
			for (int j = 1; j <= 1000; j++)
				sum[i][j] += sum[i][j - 1];
		}
		while (q--)
		{
			int h1, h2, w1, w2;
			scanf("%d%d%d%d", &h1, &w1, &h2, &w2);
			LL ans = 0;
			for (int i = h1 + 1; i < h2; i++)
				ans += sum[i][w2 - 1] - sum[i][w1];
			printf("%lld\n", ans);
		}
	}
	return 0;
}