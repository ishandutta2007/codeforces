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
LL check(vector<int> &v, int n)
{
	LL sum = 0;
	LL ans = 0;
	for (auto& x : v)
	{
		ans += (n - x + 1) * sum;
		sum += x;
	}
	return ans;
}
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
		map<int, vector<int>> mc;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x].push_back(i);
		}
		LL ans = 0;
		for (auto& p : mc)
		{
			ans += check(p.second, n);
		}
		printf("%lld\n", ans);
	}
	return 0;
}