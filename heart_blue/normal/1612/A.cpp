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
const int N = 4e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if ((x + y) & 1)
		{
			puts("-1 -1");
			continue;
		}
		int flag = 0;
		int len = (x + y) / 2;
		for (int i = 0; i <= len; i++)
		{
			int j = len - i;
			if (abs(x - i) + abs(y - j) == len)
			{
				printf("%d %d\n", i, j);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			puts("-1 -1");
	}
	return 0;
}