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
const int N = 3e5 + 10;
int a[N];
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
		vector<pair<int, int>> ans;
		for (int i = 1; i <= n; i++) a[i] = i;
		int key = n;
		for (int i = n - 1; i >= 2; i--)
		{
			if (1LL * (i - 1) * (i - 1) < a[key])
			{
				ans.emplace_back(key, i);
				a[key] = (a[key] + i - 1) / i;
				int x = i;
				if (a[x] > a[key]) swap(x, key);
				ans.emplace_back(x, key);
				a[x] = 1;
			}
			else
			{
				ans.emplace_back(i, key);
				a[i] = 1;
			}
		}
		printf("%d\n", ans.size());
		for (auto [x, y] : ans)
			printf("%d %d\n", x, y);
	}
	return 0;
}