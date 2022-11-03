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
const int N = 5e1 + 10;
int a[10][10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(a, 0);
		int n;
		scanf("%d", &n);
		for (int o = 0; o < n; o++)
		{
			int b[10];
			for (int i = 0; i < 5; i++) scanf("%d", &b[i]);
			for (int i = 0; i < 5; i++)
			{
				for (int j = i; j < 5; j++)
				{
					if (b[i] * b[j] == 1)
						a[i][j]++;
				}
			}
		}
		int flag = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 5; j++)
			{
				int x = a[i][i];
				int y = a[j][j];
				int z = a[i][j];
				x -= z;
				y -= z;
				if (x > n / 2 || y > n / 2) continue;
				if (x + y + z == n)
					flag = 1;
			}
		}
		if (flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}