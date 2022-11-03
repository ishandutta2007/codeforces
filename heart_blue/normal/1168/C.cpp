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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int last[N];
int r[N][20];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	MEM(r, 0x3f);
	for (int i = n; i >= 1; i--)
	{
		for (int o = 0; o < 20; o++)
		{
			if (a[i] >> o & 1)
			{
				int j = last[o];
				last[o] = i;
				r[i][o] = i;
				if (j > n) continue;
				for (int k = 0; k < 20; k++)
				{
					r[i][k] = min(r[i][k], r[j][k]);
				}
			}
		}
	}
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int flag = 0;
		for (int o = 0; o < 20; o++)
		{
			if (a[r] >> o & 1)
			{
				if (::r[l][o] <= r)
				{
					flag = 1;
				}
			}
		}
		if (flag) puts("Shi");
		else puts("Fou");
	}
	return 0;
}