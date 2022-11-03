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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N];
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
		LL tot = 1;
		LL sum = 0;
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			while (a[i] % 2 == 0)
			{
				a[i] /= 2;
				tot *= 2;
			}
			sum += a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, sum + (tot - 1) * a[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}