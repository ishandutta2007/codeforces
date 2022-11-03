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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 6e5 + 10;
int minv[N];
int maxv[N];
int last[N];
vector<pair<int, int>> qr[N];
class BIT
{
public:
	int a[N];
	void add(int x, int val)
	{
		if (x == 0) return;
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
} b;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		minv[i] = maxv[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int x = n - i + 1;
		last[x] = i;
		b.add(i, 1);
	}
	for (int i = n + 1; i <= n + m; i++)
	{
		int x;
		scanf("%d", &x);
		b.add(last[x], -1);
		maxv[x] = max(maxv[x], b.sum(i) - b.sum(last[x]) + 1);
		minv[x] = 1;
		b.add(i, 1);
		last[x] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		maxv[i] = max(maxv[i], b.sum(n + m) - b.sum(last[i]) + 1);
		printf("%d %d\n", minv[i], maxv[i]);
	}
	return 0;
}