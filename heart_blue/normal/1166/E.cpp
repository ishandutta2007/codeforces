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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
bitset<10010> b[51];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		int sz;
		scanf("%d", &sz);
		while (sz--)
		{
			int x;
			scanf("%d", &x);
			b[i][x] = 1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if ((b[i] & b[j]).count() == 0)
			{
				puts("impossible");
				return 0;
			}
		}
	}
	puts("possible");
	return 0;
}