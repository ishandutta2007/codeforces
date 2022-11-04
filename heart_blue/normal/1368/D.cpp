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
const int N = 2e2 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		for (int o = 0; x >> o; o++)
			cnt[o] += x >> o & 1;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = 0;
		for (int o = 0; o < 20; o++)
		{
			if (cnt[o] == 0) continue;
			cnt[o]--;
			x |= 1 << o;
		}
		ans += 1LL * x * x;
	}
	printf("%lld\n", ans);
	return 0;
}