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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int flag[N];
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	std::random_device rd;
	std::mt19937 mt(rd());
	int n;
	scanf("%d", &n);
	auto getran = [&]() -> int
	{
		return mt() % n + 1;
	};
	MEM(flag, 0);
	int ks = 0;
	LL tot1 = 0;
	LL tot2 = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), tot1 += a[i];
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]), tot2 += b[i];
	while (1)
	{
		ks++;
		LL sum1 = 0, sum2 = 0;
		int k = n / 2 + 1;
		int getans = 0;
		while (k)
		{
			int x = getran();
			if (flag[x] == ks) continue;
			k--;
			flag[x] = ks;
			sum1 += a[x];
			sum2 += b[x];
			if (sum1 * 2 > tot1 && sum2 * 2 > tot2)
			{
				getans = 1;
				break;
			}
		}
		if (getans) break;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (flag[i] == ks) ans++;
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == ks) printf("%d ", i);
	}
	return 0;
}