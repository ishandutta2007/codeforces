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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int m, s;
		scanf("%d%d", &m, &s);
		map<int, int> mc;
		int maxv = 0;
		for (int i = 1; i <= m; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x] = 1;
			maxv = max(maxv, x);
		}
		for (int i = 1; i <= maxv; i++)
		{
			if (mc[i] == 0)
				s -= i, mc[i] = 1;
		}
		while (s > 0)
			s -= ++maxv;
		if (s == 0) puts("YES");
		else puts("NO");
		
	}
	return 0;
}