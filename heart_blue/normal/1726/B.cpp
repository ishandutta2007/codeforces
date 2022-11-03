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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (m < n)
		{
			puts("No");
			continue;
		}
		if (n & 1)
		{
			puts("Yes");
			for (int i = 1; i < n; i++) printf("1 ");
			printf("%d\n", m - n + 1);
		}
		else if (m & 1) puts("No");
		else
		{
			puts("Yes");
			for (int i = 1; i + 2 <= n; i++) printf("1 ");
			int x = m - n + 2;
			printf("%d %d\n", x / 2, x / 2);
		}
	}
	return 0;
}