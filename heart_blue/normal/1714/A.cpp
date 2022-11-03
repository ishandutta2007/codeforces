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
typedef long long LLL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL sum1[N];
LL sum2[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, h, m;
		scanf("%d%d%d", &n, &h, &m);
		int cur = h * 60 + m;
		int ans = INF;
		while (n--)
		{
			scanf("%d%d", &h, &m);
			int o = h * 60 + m;
			if (o < cur) o += 24 * 60;
			ans = min(ans, o - cur);
		}
		printf("%d %d\n", ans / 60, ans % 60);
	}
	return 0;
}