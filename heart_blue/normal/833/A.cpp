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
const int N = 1e6 + 10;
LL p[N];

void init()
{
	for (int i = 0; i < N; i++) p[i] = 1LL*i*i*i;
}
bool check(int x, int y)
{
	if ((x + y) % 3) return false;
	while (x > 0 && y > 0)
	{
		if (x < y) swap(x, y);
		x -= 2;
		y -= 1;
	}
	return x == 0 && y == 0;
}
int getcnt(int x, int a)
{
	int cnt = 0;
	while (a%x == 0) cnt++, a /= x;
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	init();
	while (ncase--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int x = lower_bound(p, p + N, 1LL*a*b) - p;
		if (p[x] != 1LL*a*b)
		{
			puts("No");
			continue;
		}
		int flag = 1;
		for (int i = 2; i * i <= x; i++)
		{
			if (x%i) continue;
			while (x%i == 0) x /= i;
			int cnt1 = getcnt(i, a);
			int cnt2 = getcnt(i, b);
			if (!check(cnt1, cnt2))
			{
				flag = 0;
				break;
			}
		}
		if (!flag)
		{
			puts("No");
			continue;
		}
		if (x == 1)
		{
			puts("Yes");
			continue;
		}
		int cnt1 = getcnt(x, a);
		int cnt2 = getcnt(x, b);
		if (check(cnt1, cnt2)) puts("Yes");
		else puts("No");
	}

	return 0;
}