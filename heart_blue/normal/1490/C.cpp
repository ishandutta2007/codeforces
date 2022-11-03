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
const int N = 1e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	map<LL, int> mc;
	for (int i = 1; i <= 10000; i++)
	{
		mc[1LL * i * i * i] = 1;
	}
	while (ncase--)
	{
		LL n;
		scanf("%lld", &n);
		int flag = 0;
		for (int i = 1; 1LL * i * i * i <= n; i++)
		{
			if (mc.count(n - 1LL * i * i * i))
			{
				flag = 1;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}