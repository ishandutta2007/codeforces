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
const int N = 1e5 + 10;
tuple<int, int, int> a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[i] = make_tuple(x, y, z);
	}
	LL ans = 0;
	while (k--)
	{
		int o;
		scanf("%d", &o);
		for (int i = 1; i <= m; i++)
		{
			int x, y, z;
			tie(x, y, z) = a[i];
			if (o >= x && o <= y)
			{
				ans += o - x + z;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}