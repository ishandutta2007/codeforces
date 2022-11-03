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
class BIT
{
public:
	int a[N];
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret = max(ret, a[x]);
			x -= x & -x;
		}
		return ret;
	}
	void add(int x)
	{
		int val = sum(x - 1) + 1;
		while (x < N)
		{
			a[x] = max(a[x], val);
			x += x & -x;
		}
	}
} b;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x <= i)
			vp.emplace_back(i - x, x);
	}
	sort(vp.begin(), vp.end());
	for (auto& [d, x] : vp)
	{
		b.add(x);
	}
	printf("%d\n", b.sum(N - 1));
	return 0;
}