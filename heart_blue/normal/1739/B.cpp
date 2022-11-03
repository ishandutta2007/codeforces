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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
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
		int flag = 0;
		for (int i = 2; i <= n; i++)
		{
			if (a[i] == 0)
			{
				a[i] += a[i - 1];
				continue;
			}
			if (a[i - 1] - a[i] >= 0)
			{
				flag = 1;
				continue;
			}
			a[i] += a[i - 1];
		}
		if (flag) puts("-1");
		else
		{
			for (int i = 1; i <= n; i++)
				printf("%d%c", a[i], " \n"[i == n]);
		}
	}
	return 0;
}