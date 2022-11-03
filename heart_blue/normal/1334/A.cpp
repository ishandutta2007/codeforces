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
		int pre1 = -INF, pre2 = -INF;
		int flag = 1;
		while (n--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (x < y) flag = 0;
			if (x < pre1) flag = 0;
			if (y < pre2) flag = 0;
			if (x - pre1 < y - pre2) flag = 0;
			pre1 = x;
			pre2 = y;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}