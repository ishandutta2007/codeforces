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
const int N = 2e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int sum1 = 0;
		int sum2 = 0;
		int maxv1 = 0;
		int maxv2 = 0;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			sum1 += x;
			maxv1 = max(maxv1, sum1);
		}
		int m;
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			int x;
			scanf("%d", &x);
			sum2 += x;
			maxv2 = max(maxv2, sum2);
		}
		printf("%d\n", maxv1 + maxv2);
	}
	return 0;
}