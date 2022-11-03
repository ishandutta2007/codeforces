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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int fa[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	v[0].push_back(1);
	int cur = 1;
	int n, t, k;
	scanf("%d%d%d", &n, &t, &k);
	int sum = 1;
	for (int i = 1; i <= t; i++)
	{
		int sz;
		scanf("%d", &sz);
		sum += sz - 1;
		while (sz--)
		{
			int x = ++cur;
			fa[x] = v[i - 1].front();
			v[i].push_back(x);
		}
	}
	for (int i = 2; i <= t; i++)
	{
		int minv = min(v[i - 1].size(), v[i].size());
		for (int j = 1; j < minv && sum > k; j++)
		{
			fa[v[i][j]] = v[i - 1][j];
			sum--;
		}
	}
	if (sum != k)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n", n);
	for (int i = 2; i <= n; i++)
	{
		printf("%d %d\n", fa[i], i);
	}
	return 0;
}