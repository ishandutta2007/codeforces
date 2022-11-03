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
const int N = 2e5 + 20;
int sum[N];
LL solve(int n, LL len)
{
	return len / n * sum[n] + sum[len % n];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b, q;
		scanf("%d%d%d", &a, &b, &q);
		for (int i = 1; i <= a * b; i++)
		{
			sum[i] = sum[i - 1] + (i % a % b != i % b % a);
		}
		while (q--)
		{
			LL l, r;
			scanf("%lld%lld", &l, &r);
			printf("%lld ", solve(a * b, r) - solve(a * b, l - 1));
		}
		puts("");
	}
	return 0;
}