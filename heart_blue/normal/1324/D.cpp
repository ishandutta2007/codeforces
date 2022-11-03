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
class BIT
{
	int a[N];
public:
	void add(int x)
	{
		while (x < N)
		{
			a[x] ++;
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} b;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	vector<pair<int, int>> vp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		vp.emplace_back(x, i);
	}
	for (auto& p : vp)
	{
		int x;
		scanf("%d", &x);
		p.first -= x;
	}
	sort(vp.begin(), vp.end());
	int ptr = vp.size() - 1;
	LL ans = 0;
	for (auto& p : vp)
	{
		while (ptr >= 0 && p.first > -vp[ptr].first)
		{
			b.add(vp[ptr].second);
			ptr--;
		}
		ans += b.sum(p.second - 1);
	}
	printf("%lld\n", ans);

	return 0;
}