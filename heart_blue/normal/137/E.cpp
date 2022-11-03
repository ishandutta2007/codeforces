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
const int N = 1e6 + 10;
class BIT
{
public:
	int a[N];
	BIT()
	{
		MEM(a, 0x3f);
	}
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] = min(a[x], val);
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = INF;
		while (x)
		{
			ret = min(ret, a[x]);
			x -= x & -x;
		}
		return ret;
	}
} b;
char str[N];
int flag[200];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fill(flag, flag + 200, 2);
	flag['a'] = -1;
	flag['e'] = -1;
	flag['i'] = -1;
	flag['o'] = -1;
	flag['u'] = -1;
	int o = 3e5;
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	int len = 0;
	int cnt = 0;
	b.add(o, 0);
	for (int i = 1; i <= n; i++)
	{
		o += flag[tolower(str[i])];
		int pos = b.sum(o);
		b.add(o, i);
		if (i - pos > len) len = i - pos, cnt = 0;
		if (i - pos == len) cnt++;
	}
	if (len <= 0) puts("No solution");
	else printf("%d %d\n", len, cnt);
	return 0;
}