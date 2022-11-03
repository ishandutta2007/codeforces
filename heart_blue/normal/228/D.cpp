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
const int N = 1e5 + 10;
class BIT
{
	LL a[N];
public:
	void init()
	{
		MEM(a, 0);
	}
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] += val;
			x += x & -x;
		}
	}
	LL sum(int x)
	{
		LL ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} b[5][12];
int a[N];
vector<int> key[10];
void init()
{
	for (int o = 2; o <= 6; o++)
	{
		for (int i = 1; i <= o; i++) key[o].push_back(i);
		for (int i = o - 1; i > 1; i--) key[o].push_back(i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		for (int j = 2; j <= 6; j++)
		{
			int len = 2 * j - 2;
			int r = i % len;
			b[j - 2][r].add(i, x);
		}
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int pos, val;
			scanf("%d%d", &pos, &val);
			for (int j = 2; j <= 6; j++)
			{
				int len = 2 * j - 2;
				int r = pos % len;
				b[j - 2][r].add(pos, val - a[pos]);
			}
			a[pos] = val;
		}
		else
		{
			LL ans = 0;
			int l, r, z;
			scanf("%d%d%d", &l, &r, &z);
			auto& v = key[z];
			
			for (int i = 0; i < v.size(); i++)
			{
				int o = (l + i) % v.size();
				ans += (b[z - 2][o].sum(r) - b[z - 2][o].sum(l - 1))* v[i];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}