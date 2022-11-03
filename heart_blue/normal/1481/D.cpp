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
const int N = 1e3 + 10;
char str[N][N];
void output(int x, int y, int m)
{
	int a[] = { x,y };
	for (int i = 0; i <= m; i++)
	{
		printf("%d ", a[i & 1]);
	}
}
void check(int n, int m)
{
	if (m % 2 == 1)
	{
		puts("YES");
		output(1, 2, m);
		puts("");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (str[i][j] == str[j][i])
			{
				puts("YES");
				output(i + 1, j + 1, m);
				puts("");
				return;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		int kx = -1;
		int ky = -1;
		for (int j = 0; j < n; j++)
		{
			if (str[i][j] == 'a') kx = j;
			if (str[i][j] == 'b') ky = j;
		}
		if (kx == -1 || ky == -1) continue;
		puts("YES");
		if (m % 4 == 2)
		{
			output(kx + 1, i + 1, m / 2);
			output(ky + 1, i + 1, m / 2 - 1);
		}
		else
		{
			output(i + 1, kx + 1, m / 2);
			output(ky + 1, i + 1, m / 2 - 1);
		}
		puts("");
		return;
	}
	puts("NO");
	return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
		}
		check(n, m);
	}
	return 0;
}