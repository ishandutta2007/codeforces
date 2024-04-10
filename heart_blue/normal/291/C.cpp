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
unsigned int a[N];
unsigned int readint()
{
	unsigned int a, b, c, d;
	scanf("%u.%u.%u.%u", &a, &b, &c, &d);
	return (a << 24) | (b << 16) | (c << 8) | d;
}
void getans(unsigned int x)
{
	printf("%d.%d.%d.%d\n",
		x >> 24 & 0xff,
		x >> 16 & 0xff,
		x >> 8 & 0xff,
		x & 0xff);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) a[i] = readint();
	unsigned int x = 0xffffffff;
	unsigned int key = -1;
	while (1)
	{
		x <<= 1;
		if (x == 0) break;
		map<unsigned int, int> mc;
		for (int i = 1; i <= n; i++)
		{
			mc[x&a[i]] = 1;
		}
		if (mc.size() == k)
		{
			key = x;
		}
	}
	if (key == -1) puts("-1");
	else getans(key);
	return 0;
}