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
#include <iterator>
#include <complex>
#include <valarray>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, l;
		scanf("%d%d", &n, &l);
		MEM(cnt, 0);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			for (int o = 0; o < l; o++)
			{
				if (x >> o & 1)
					cnt[o]++;
			}
		}
		int ans = 0;
		for (int o = 0; o < l; o++)
		{
			if (cnt[o] * 2 >= n)
				ans |= 1 << o;
		}
		printf("%d\n", ans);
	}
	return 0;
}