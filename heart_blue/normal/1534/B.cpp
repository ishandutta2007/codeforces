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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
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
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		a[n + 1] = 0;
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int o = a[i] - max(a[i - 1], a[i + 1]);
			o = max(0, o);
			ans += o;
			a[i] -= o;
		}
		for (int i = 0; i <= n; i++)
		{
			ans += abs(a[i] - a[i + 1]);
		}
		printf("%lld\n", ans);

	}
	return 0;
}