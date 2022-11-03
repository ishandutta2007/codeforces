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
const int N = 2e5 + 10;

LL a[N];
LL b[N];
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
		LL sum = 0;
		LL tot = 1LL * n * (n + 1) / 2;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
			sum += b[i];
		}
		if (sum % tot)
		{
			puts("NO");
			continue;
		}
		sum /= tot;
		/*
		1 4 3 2
		2 1 4 3
		3 2 1 4
		4 3 2 1
		*/
		int flag = 1;
		for (int i = 1; i < n; i++)
		{
			LL x = b[i] + sum - b[i + 1];
			if (x % n)
			{
				flag = 0;
				break;
			}
			a[i + 1] = x / n;
			if (a[i + 1] > 1000000000 || a[i + 1] < 1)
			{
				flag = 0;
				break;
			}
		}
		a[1] = sum;
		for (int i = 2; i <= n; i++)
		{
			a[1] -= a[i];
		}
		if (a[1] < 1 || a[1] > 1000000000 || flag == 0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1; i <= n; i++)
			printf("%lld%c", a[i], " \n"[i == n]);

	}
	return 0;
}