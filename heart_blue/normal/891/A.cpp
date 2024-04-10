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
int a[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> mc;
	int g = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		g = gcd(a[i], g);
		mc[a[i]]++;
	}
	if (g != 1)
	{
		puts("-1");
		return 0;
	}
	if (mc[1] > 0)
	{
		printf("%d\n", n - mc[1]);
		return 0;
	}
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		int g = 0;
		for (int j = i; j <= n; j++)
		{
			g = gcd(g, a[j]);
			if (g == 1)
			{
				ans = min(ans, j - i + n - 1);
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}