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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
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
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (n == 1)
		{
			puts("0");
			continue;
		}
		vector<pair<int, int>> ans;
		if ((a[1] + a[n]) % 2 == 1) a[n] = a[1];
		else a[1] = a[n];
		ans.emplace_back(1, n);
		for (int i = 2; i < n; i++)
		{
			if ((a[1] + a[i]) % 2 == 1) ans.emplace_back(1, i);
			else ans.emplace_back(i, n);
		}
		printf("%d\n", ans.size());
		for (auto [l, r] : ans)
			printf("%d %d\n", l, r);
	}
	return 0;
}