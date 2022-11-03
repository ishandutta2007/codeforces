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
const int N = 3e5 + 10;
int s[N], g[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i] >> g[i];
		g[i] += s[i];
	}
	for (int i = 2; i <= n; i++)
	{
		if (g[i] > g[i - 1]) g[i] = g[i - 1] + 1;
	}
	for (int i = n - 1; i > 0; i--)
	{
		if (g[i] > g[i + 1]) g[i] = g[i + 1] + 1;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (g[i] < s[i])
		{
			cout << -1 << endl;
			return 0;
		}
		ans += g[i] - s[i];
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++) printf("%d ", g[i]);

	return 0;
}