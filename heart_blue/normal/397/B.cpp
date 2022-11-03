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
const int N = 1e5 + 10;
int p[N];
int flag[N];
void init()
{
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		p[k++] = i;
		for (int j = i + i; j < N; j += i)
			flag[j] = 1;
	}
}
bool check(int n)
{
	for (int i = 0; p[i] * p[i] <= n; i++)
	{
		if (n % p[i] == 0) return false;
	}
	return true;
}
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, l, r;
		scanf("%d%d%d", &n, &l, &r);
		LL l1 = 0, r1 = 0;
		if (l == r)
		{
			if (n % l == 0) n = l;
			else n = -1;
		}
		while (n > r1)
		{
			LL l2 = l1 + l;
			LL r2 = r1 + r;
			if (l2 <= r1)
			{
				l1 = r1 = n;
				break;
			}
			l1 = l2;
			r1 = r2;
		}
		if (l1 <= n && n <= r1) puts("Yes");
		else puts("No");

	}
	return 0;
}