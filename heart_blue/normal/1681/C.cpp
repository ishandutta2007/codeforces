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
int a[N];
int b[N];
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
		vector<pair<int, int>> vp;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++)
		{
			int k = i;
			for (int j = i + 1; j <= n; j++)
			{
				if (a[j] <= a[k] && b[j] <= b[k])
					k = j;
			}
			if(i != k)
				vp.emplace_back(i, k);
			swap(a[i], a[k]);
			swap(b[i], b[k]);
		}
		if (is_sorted(a + 1, a + n + 1) && is_sorted(b + 1, b + n + 1))
		{
			printf("%d\n", vp.size());
			for (auto& [x, y] : vp)
				printf("%d %d\n", x, y);
		}
		else
			puts("-1");
	}
	return 0;
}