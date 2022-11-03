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
		int sum = 0;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum ^= a[i];
		}
		if (sum == 0)
		{
			puts("DRAW");
			continue;
		}
		int o = 0;
		for (o = 30; o >= 0; o--)
		{
			if (sum >> o & 1)
				break;
		}
		int cnt0 = 0, cnt1 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] >> o & 1) cnt1++;
			else cnt0++;
		}
		if ((cnt1 / 2) & 1)
		{
			if (cnt0 & 1) puts("WIN");
			else puts("LOSE");
		}
		else
		{
			puts("WIN");
		}
	}
	return 0;
}