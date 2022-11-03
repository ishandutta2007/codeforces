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
typedef __int128 LLL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
class BIT
{
	LLL a[N];
public:
	void add(int x, LL val)
	{
		while (x < N)
		{
			a[x] += val;
			x += x & -x;
		}
	}
	LLL sum(int x)
	{
		LLL ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} b[11][11];
char str[N];
LL p[200];
void add(int pos, char c, int o)
{
	LL val = p[c] * o;
	for (int i = 1; i <= 10; i++)
		b[i][pos % i].add(pos, val);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL k = 100001;
	p['A'] = 1;
	p['T'] = k;
	p['C'] = k * k;
	p['G'] = k * k * k;
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for (int i = 1; i <= n; i++)
	{
		add(i, str[i], 1);
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op;
		scanf("%d", &op);
		if (op == 2)
		{
			int l, r;
			char s[12];
			scanf("%d%d%s", &l, &r, s + 1);
			int m = strlen(s + 1);
			int ans = 0;
			for (int i = 1; i <= m; i++)
			{
				int pos = (l + i - 1);
				int o = pos % m;
				LLL tot = b[m][o].sum(r) - b[m][o].sum(l - 1);
				ans += tot / p[s[i]] % k;
			}
			printf("%d\n", ans);
		}
		else
		{
			int pos;
			char c;
			scanf("%d %c", &pos, &c);
			add(pos, str[pos], -1);
			str[pos] = c;
			add(pos, str[pos], 1);
		}
	}
	return 0;
}