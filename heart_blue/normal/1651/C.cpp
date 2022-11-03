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
LL ans[100];
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(ans, 0x3f);
		int minv1, minv2, minv3, minv4;
		minv1 = minv2 = minv3 = minv4 = INF;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		ans[0b0101] = abs(a[1] - b[1]);
		ans[0b1001] = abs(a[1] - b[n]);
		ans[0b0110] = abs(a[n] - b[1]);
		ans[0b1010] = abs(a[n] - b[n]);
		for (int i = 1; i <= n; i++)
		{
			minv1 = min(minv1, abs(a[1] - b[i]));
			minv2 = min(minv2, abs(a[n] - b[i]));
			minv3 = min(minv3, abs(a[i] - b[1]));
			minv4 = min(minv4, abs(a[i] - b[n]));
		}
		ans[0b0001] = minv1;
		ans[0b0010] = minv2;
		ans[0b0100] = minv3;
		ans[0b1000] = minv4;
		ans[0] = 0;
		for (int s = 1; s < 16; s++)
		{
			for (int o = s; o > 0; o = (o - 1) & s)
			{
				ans[s] = min(ans[s], ans[o] + ans[s ^ o]);
			}
		}
		printf("%lld\n", ans[15]);
	}
	return 0;
}