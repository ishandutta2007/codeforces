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
const int N = 2e3 + 10;
LL sum(int n)
{
	return 1LL * n * (n - 1) / 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	map<int, int> mc;
	int mask = (1 << k) - 1;
	int cur = 0;
	mc[cur]++;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cur ^= x;
		mc[min(cur, cur ^ mask)]++;
	}
	LL ans = 1LL * n * (n + 1) / 2;
	for (auto& p : mc)
	{
		int x = p.second;
		ans -= sum(x / 2) + sum((x + 1) / 2);
	}
	printf("%lld\n", ans);
	return 0;
}