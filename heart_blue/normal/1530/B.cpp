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
char str[30][30];
void add(int x, int y)
{
	str[x][y] = '0';
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (str[x + i][y + j] == '1') return;
		}
	}
	str[x][y] = '1';
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(str, '0');
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			if (i == 1 || i == n)
			{
				for (int j = 1; j <= m; j++)
					add(i, j);
			}
			else
			{
				add(i, 1);
				add(i, m);
			}
			str[i][m + 1] = 0;
			puts(str[i] + 1);
		}
	}
	return 0;
}