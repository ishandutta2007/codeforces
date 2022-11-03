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
int a[N][N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	while (k--)
	{

		int x = 1;
		int y;
		scanf("%d", &y);
		int c = y;
		if (flag[y])
		{
			printf("%d ", y);
			continue;
		}
		int ok = 1;
		while (x <= n)
		{
			if (a[x][y] == 1)
				a[x][y++] = 2;
			else if (a[x][y] == 2)
				x++;
			else
				a[x][y--] = 2;
			if (y != c) ok = 0;
		}
		flag[c] = ok;
		printf("%d ", y);
	}
	return 0;
}