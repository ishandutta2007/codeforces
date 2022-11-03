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
const int N = 5e3 + 300;
char str[N];
int a[N][N];
int flag[N];
int key[] = {
0,0,0,0,
0,0,0,1,
0,0,1,0,
0,0,1,1,
0,1,0,0,
0,1,0,1,
0,1,1,0,
0,1,1,1,
1,0,0,0,
1,0,0,1,
1,0,1,0,
1,0,1,1,
1,1,0,0,
1,1,0,1,
1,1,1,0,
1,1,1,1 };
inline void add(int* a, char c)
{
	int x;
	if (c >= 'A') x = c - 'A' + 10;
	else x = c - '0';
	x *= 4;
	a[0] = key[x];
	a[1] = key[x + 1];
	a[2] = key[x + 2];
	a[3] = key[x + 3];
}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		for (int j = 0, k = 0; j < n; j += 4, k++)
		{
			add(&a[i][j], str[k]);
		}
	}
	flag[n] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n)
			{
				if (a[i][j] ^ a[i][j + 1])
				{
					flag[j + 1] = 1;
				}
			}
			if (i + 1 < n)
			{
				if (a[i][j] ^ a[i + 1][j])
				{
					flag[i + 1] = 1;
				}
			}
		}
	}
	int g = 0;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i])
			g = gcd(g, i);
	}
	printf("%d\n", g);
	return 0;
}