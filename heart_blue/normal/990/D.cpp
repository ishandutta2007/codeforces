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
const int N = 1e3 + 10;
char c[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	if (min(a, b) != 1)
	{
		puts("NO");
		return 0;
	}
	if (n > 1 && n <= 3 && a == 1 && b == 1)
	{
		puts("NO");
		return 0;
	}
	int tot = max(a, b);
	MEM(c, '0');
	for (int i = 0; i < n; i++) c[i][n] = 0;
	if (tot < n)
	{
		for (int i = tot; i < n; i++)
		{
			c[i][i - 1] = c[i - 1][i] = '1';
		}
	}
	if (a == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) continue;
				c[i][j] ^= 1;
			}
		}
	}
	puts("YES");
	for (int i = 0; i < n; i++) puts(c[i]);
	return 0;
}