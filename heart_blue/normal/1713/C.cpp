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
const int N = 2e5 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);

		for (int i = n - 1; i >= 0; i--)
		{
			int p = i;
			while (1)
			{
				int x = sqrt(p + i) + 0.5;
				if (x * x == p + i)
				{
					break;
				}
				p--;
			}
			for (int j = p; j <= i; j++)
			{
				ans[j] = i + p - j;
			}
			i = p;
		}
		for (int i = 0; i < n; i++)
			printf("%d%c", ans[i], " \n"[i + 1 == n]);
	}
	return 0;
}