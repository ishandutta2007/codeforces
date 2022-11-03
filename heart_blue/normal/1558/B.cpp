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
const int N = 4e6 + 10;
LL ans[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int mod;
	scanf("%d", &n);
	scanf("%d", &mod);
	LL cur = 0;
	LL pre = ans[1];
	sum[1] = 1;
	sum[2] = -1;
	for (int i = 1; i <= n; i++)
	{
		ans[i] += pre;
		cur += sum[i];
		cur %= mod;
		ans[i] += cur;
		ans[i] %= mod;
		pre = (pre + ans[i]) % mod;
		for (int j = 2; i * j <= n; j++)
		{
			int l = i * j;
			int r = min(n + 1, j * (i + 1));
			sum[l] = (sum[l] + ans[i]) % mod;
			sum[r] = (sum[r] - ans[i] + mod) % mod;
		}
	}
	printf("%lld\n", ans[n]);
	return 0;
}