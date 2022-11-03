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
		int n;
		scanf("%d", &n);
		LL l = n;
		LL r = n + 1;
		while (!check(l)) l--;
		while (!check(r)) r++;
		LL u1 = l - 2;
		LL d1 = 2 * l;
		LL u2 = (n - l + 1);
		LL d2 = l * r;
		LL u = u1 * r + u2 * 2;
		LL d = 2 * l * r;
		LL g = gcd(u, d);
		printf("%lld/%lld\n", u / g, d / g);

	}
	return 0;
}