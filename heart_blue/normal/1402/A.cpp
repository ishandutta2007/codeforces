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
const int N = 5e3 + 10;
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int n;
	cin >> n;
	for (int i = 1; i <= b; i++)
	{
		for (int j = 1; j <= a; j++)
		{
			flag[i][j] = 1;
		}
	}
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			flag[i][j + a] = 1;
		}
	}
	int x = 1, y = 1;
	int dy = 1;
	if (b > d)
	{
		if (d & 1) y = a + c, dy = -1;
	}
	else
	{
		if (b % 2 == 0) y = a + c, dy = -1;
	}
	for (int o = 1; o <= n; o++)
	{
		int w;
		cin >> w;
		while (w--)
		{
			flag[x][y] = o - 1 + 'a';
			if (flag[x][y + dy] == 0)
			{
				x++;
				dy = -dy;
			}
			else
			{
				y += dy;
			}
		}
	}
	puts("YES");
	for (int i = 1; i <= max(b, d); i++)
	{
		for (int j = 1; j <= a + c; j++)
		{
			if (isalpha(flag[i][j])) putchar(flag[i][j]);
			else putchar('.');
		}
		puts("");
	}
	return 0;
}