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
const int N = 2.5e6 + 10;
vector<pair<int, int>> vp[N];
pair<int, int> a[N / 10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			int o = a[i].first - a[j].first;
			for (auto [x, y] : vp[o])
			{
				if (x == i || x == j || y == i || y == j) continue;
				puts("YES");
				printf("%d %d %d %d\n", a[x].second, a[j].second, a[y].second, a[i].second);
				return 0;
			}
			vp[o].emplace_back(i, j);
		}
	}
	puts("NO");
	return 0;
}