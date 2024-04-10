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
const int N = 2e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int atk, hp, n;
		scanf("%d%d%d", &atk, &hp, &n);
		LL tot = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++)
		{
			tot += 1LL * (b[i] + atk - 1) / atk * a[i];
		}
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (tot - 1LL * (b[i] + atk - 1) / atk * a[i] < hp)
			{
				LL cur = hp - tot + 1LL * (b[i] + atk - 1) / atk * a[i];
				if ((cur + a[i] - 1) / a[i] >= (b[i] + atk - 1) / atk)
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}