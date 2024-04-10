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
const int N = 3e5 + 10;
int sum[30];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
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
		MEM(sum, 0);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			for (int o = 0; x >> o; o++)
			{
				if (x >> o & 1)
					sum[o]++;
			}
		}
		int g = 0;
		for (int i = 0; i < 30; i++)
			g = gcd(g, sum[i]);
		for (int i = 1; i <= n; i++)
		{
			if (g % i == 0)
				printf("%d ", i);
		}
		puts("");
	}
	return 0;
}