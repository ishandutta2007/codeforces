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
const int N = 2e6 + 10;
int flag[N];
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
		for (int i = 1; i <= n; i++) flag[i] = 0;
		int rest1 = 0;
		for (int i = 1; i <= n; i++)
		{
			int sz;
			scanf("%d", &sz);
			int key = 0;
			while (sz--)
			{
				int x;
				scanf("%d", &x);
				if (flag[x]) continue;
				else if (key == 0) key = x;
			}
			flag[key] = 1;
			if (key == 0) rest1 = i;
		}
		int rest2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] == 0)
				rest2 = i;
		}
		if (rest1 == 0) puts("OPTIMAL");
		else
		{
			puts("IMPROVE");
			printf("%d %d\n", rest1, rest2);
		}
	}
	return 0;
}