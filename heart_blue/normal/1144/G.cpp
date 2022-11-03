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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int ans[N];
vector<pair<int, int>> vp1, vp2;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	vp1.emplace_back(-INF, 0);
	vp2.emplace_back(INF, 0);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > vp1.back().first && a[i] < vp2.back().first && i != n)
		{
			if (a[i + 1] == a[i])
			{
				vp1.emplace_back(a[i], i);
				vp2.emplace_back(a[i], i + 1);
				i++;
			}
			else if (a[i + 1] > a[i])
			{
				vp1.emplace_back(a[i], i);
			}
			else
			{
				vp2.emplace_back(a[i], i);
			}
			continue;
		}
		else if (a[i] > vp1.back().first)
			vp1.emplace_back(a[i], i);
		else if (a[i] < vp2.back().first)
			vp2.emplace_back(a[i], i);
		else
		{
			puts("NO");
			return 0;
		}
	}
	for (auto [val, pos] : vp2)
		ans[pos] = 1;
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}