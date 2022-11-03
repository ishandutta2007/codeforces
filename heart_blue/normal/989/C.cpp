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
const int N = 1e2 + 10;
char c[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a[4];
	for (int i = 0; i < 4; i++) cin >> a[i], a[i]--;
	int sz[5] = { 0,13,26,39,50 };
	for (int o = 0; o < 4; o++)
	{
		for (int i = sz[o]; i < sz[o + 1]; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				c[i][j] = 'A' + o;
			}
			c[i][50] = 0;
		}
	}
	for (int o = 0; o < 4; o++)
	{
		for (int i = sz[o] + 1; i + 1 < sz[o + 1]; i += 2)
		{
			for (int j = 0; j < 50; j += 2)
			{
				for (int k = 0; k < 4; k++)
				{
					if (o == k) continue;
					if (a[k] == 0) continue;
					a[k]--;
					c[i][j] = k + 'A';
					break;
				}
			}
		}
	}
	puts("50 50");
	for (int i = 0; i < 50; i++) puts(c[i]);
	return 0;
}