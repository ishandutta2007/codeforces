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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
void init()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
			v[j].push_back(i);
	}
}
LL ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	scanf("%d", &n);
	for (int i = 2; i <= n; i += 2)
	{
		int o;
		scanf("%d", &o);
		pair<int, int> minv = { (int)INF,(int)INF };
		for (auto& a : v[o])
		{
			int b = o / a;
			if ((a + b) & 1) continue;
			if (a <= b) continue;
			int x = (a + b) / 2;
			int y = (a - b) / 2;
			if (y > ans[i - 2])
			{
				minv = min(minv, make_pair(x, y));
			}
		}
		if (minv.first == INF) puts("No"), exit(0);
		ans[i] = minv.first;
		ans[i - 1] = minv.second;
	}
	for (int i = n; i >= 1; i--)
	{
		ans[i] = ans[i] * ans[i] - ans[i - 1] * ans[i - 1];
	}
	puts("Yes");
	for (int i = 1; i <= n; i++)
	{
		printf("%lld ", ans[i]);
	}
	return 0;
}