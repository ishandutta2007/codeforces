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
const int N = 5e5 + 10;
class BIT
{
	int a[N];
public:
	int lowbit(int x)
	{
		return x & -x;
	}
	void add(int x, int val = 1)
	{
		while (x < N)
		{
			a[x] += val;
			x += lowbit(x);
		}
	}
	int sum(int x)
	{
		if (x <= 0) return 0;
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= lowbit(x);
		}
		return x;
	}
};
int b[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, d;
	scanf("%d%d%d", &n, &k, &d);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int ptr = 1;
	b[0] = 0;
	b[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		while (a[i] - a[ptr] > d) ptr++;
		b[i + 1] = b[i];
		if (i >= k)
		{
			b[i + 1] += b[i - k + 1] - b[ptr - 1] > 0;
		}
	}
	if (b[n + 1] - b[n] > 0) puts("YES");
	else puts("NO");
	return 0;
}