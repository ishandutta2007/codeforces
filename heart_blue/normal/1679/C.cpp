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
const int N = 1e5 + 10;
class BIT
{
public:
	int a[N];
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] += val;
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
} b1, b2;
int cnt1[N];
int cnt2[N];
void add(BIT& b, int cnt[], int x)
{
	if (cnt[x]++ == 0)
		b.add(x, 1);
}
void del(BIT& b, int cnt[], int x)
{
	if (cnt[x]-- == 1)
		b.add(x, -1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	while (q--)
	{
		int op;
		int x1, y1, x2, y2;
		scanf("%d%d%d", &op, &x1, &y1);
		if (op == 1)
		{
			add(b1, cnt1, x1);
			add(b2, cnt2, y1);
		}
		else if (op == 2)
		{
			del(b1, cnt1, x1);
			del(b2, cnt2, y1);
		}
		else
		{
			scanf("%d%d", &x2, &y2);
			if (b1.sum(x2) - b1.sum(x1 - 1) == x2 - x1 + 1 ||
				b2.sum(y2) - b2.sum(y1 - 1) == y2 - y1 + 1)
			{
				puts("Yes");
			}
			else
				puts("No");
		}
	}

	return 0;
}