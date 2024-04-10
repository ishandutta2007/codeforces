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
const int N = 1e6 + 10;
class BIT
{
public:
	int a[N];
	void add(int x)
	{
		int t = sum(x - 1) + 1;
		while (x < N)
		{
			a[x] = max(a[x], t);
			x += x & -x;
		}
	}
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
} b;
pair<int, int> p[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		p[x].first = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		p[x].second = n - i + 1;
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++)
	{
		b.add(p[i].second);
	}
	printf("%d\n", b.sum(N - 1));
	return 0;
}