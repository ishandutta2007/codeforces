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
int a[N];
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
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		if (n % 2 == 0)
		{
			for (int i = 1; i <= n; i += 2)
			{
				swap(a[i], a[i + 1]);
				a[i] *= -1;
			}
		}
		else
		{
			int x = 1, y = 2, z = 3;
			if (a[y] + a[z] == 0) swap(x, y);
			if (a[y] + a[z] == 0) swap(x, z);
			tie(a[x], a[y], a[z]) = make_tuple(a[y] + a[z], -a[x], -a[x]);
			for (int i = 4; i <= n; i += 2)
			{
				swap(a[i], a[i + 1]);
				a[i] *= -1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", a[i], " \n"[i == n]);
		}
	}
	return 0;
}