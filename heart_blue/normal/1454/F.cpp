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
int minv[20][N];
int maxv[20][N];
int cnt[N];
void init()
{
	for (int i = 2; i < N; i++)
		cnt[i] = cnt[i / 2] + 1;
}
void build(int n)
{
	for (int o = 1; o < 20; o++)
	{
		int len = 1 << (o - 1);
		for (int i = 1; i + (1 << o) - 1 <= n; i++)
		{
			minv[o][i] = min(minv[o - 1][i], minv[o - 1][i + len]);
			maxv[o][i] = max(maxv[o - 1][i], maxv[o - 1][i + len]);
		}
	}
}
int querymin(int l, int r)
{
	int len = r - l + 1;
	int k = cnt[len];
	return min(minv[k][l], minv[k][r - (1 << k) + 1]);
}
int querymax(int l, int r)
{
	int len = r - l + 1;
	int k = cnt[len];
	return max(maxv[k][l], maxv[k][r - (1 << k) + 1]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	init();
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			minv[0][i] = maxv[0][i] = x;
		}
		build(n);
		int key = -1;
		int cur = 0;
		for (int i = 1; i + 2 <= n; i++)
		{
			int l = i + 1, r = n - 1;
			cur = max(cur, minv[0][i]);
			while (l <= r)
			{
				int mid = (l + r) / 2;
				int res1 = querymin(i + 1, mid);
				int res2 = querymax(mid + 1, n);
				if (res1 == res2 && res1 == cur)
				{
					key = mid;
					break;
				}
				if (res1 > cur) l = mid + 1;
				else if (res1 < cur) r = mid - 1;
				else if (res2 > cur) l = mid + 1;
				else r = mid - 1;
			}
			if (key != -1)
			{
				puts("YES");
				printf("%d %d %d\n", i, key - i, n - key);
				break;
			}
		}
		if (key == -1) puts("NO");
	}
	return 0;
}