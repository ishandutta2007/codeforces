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
const int N = 5e5 + 10;
class BIT
{
	int a[N];
	int sz;
public:
	void init(int n)
	{
		fill(a, a + n + 1, 0);
		sz = n;
	}
	void add(int x, int val)
	{
		while (x <= sz)
		{
			a[x] ^= val;
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret ^= a[x];
			x -= x & -x;
		}
		return ret;
	}
} b;
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
		b.init(n);
		map<int, int> mc;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x] = 1;
			sum ^= b.sum(n) ^ b.sum(x);
			b.add(x, 1);
		}
		if (sum == 0 || mc.size() != n) puts("YES");
		else puts("NO");
	}
	return 0;

}