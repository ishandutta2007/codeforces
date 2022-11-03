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
int minv[N];
int sz[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	MEM(minv, 0x3f);
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (r < l) r += n;
		minv[l] = min(minv[l], r);
		sz[l]++;
	}
	for (int i = 1; i <= n; i++)
	{
		int o = i;
		int cnt = 0;
		int ans = 0;
		for (int j = 1; j <= n; j++)
		{
			if (sz[o])
			{
				ans = max(ans, (sz[o] - 1) * n + minv[o] - o + cnt);
			}
			cnt++;
			o++;
			if (o > n) o = 1;
		}
		printf("%d ", ans);
	}

	return 0;
}