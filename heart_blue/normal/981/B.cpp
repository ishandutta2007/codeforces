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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	LL ans = 0;
	map<int, int> ms;
	while (n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ms[x] = max(ms[x], y);
	}
	scanf("%d", &n);
	while (n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ms[x] = max(ms[x], y);
	}
	for (auto &p : ms)
	{
		ans += p.second;
	}
	printf("%lld\n", ans);
	return 0;
}