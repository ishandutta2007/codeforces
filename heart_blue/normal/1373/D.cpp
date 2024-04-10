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
const int N = 2e5 + 10;
int a[N];
LL solve(vector<int>& v)
{
	LL sum = 0;
	LL maxv = 0;
	for (auto& x : v)
	{
		sum = max(sum + x, x * 1LL);
		maxv = max(maxv, sum);
	}
	return maxv;
}
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		LL ans = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (i % 2 == 0)
				ans += a[i];
		}
		vector<int> v1, v2;
		for (int i = 0; i + 1 < n; i += 2)
		{
			v1.push_back(a[i + 1] - a[i]);
		}
		for (int i = 1; i + 1 < n; i += 2)
		{
			v2.push_back(a[i] - a[i + 1]);
		}
		printf("%lld\n", ans + max(solve(v1), solve(v2)));

	}
	return 0;
}