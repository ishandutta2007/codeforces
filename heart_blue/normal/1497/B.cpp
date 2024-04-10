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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		map<int, int> mc;
		int n;
		scanf("%d", &n);
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			mc[i] = 0;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			mc[x % m]++;
		}
		int ans = 0;
		for (auto& p : mc)
		{
			if (p.first == 0 || p.first * 2 == m)
			{
				if (p.second > 0)
					ans++;
			}
			else if (p.first * 2 > m) break;
			else
			{
				int x = p.second;
				int y = 0;
				if (mc.count(m - p.first))
					y = mc[m - p.first];
				if (x < y) swap(x, y);
				if (x > 0) ans++;
				x = max(0, x - y - 1);
				ans += x;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}