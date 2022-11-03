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
const int N = 4e3 + 10;
int a[N];
int b[N];
pair<LL, int> solve(int a[], int n)
{
	pair<LL, int> ret = make_pair(INF * INF, -1);
	for (int i = 0; i <= n; i++)
	{
		LL tot = 0;
		for (int j = 0; j < n; j++)
		{
			LL dx = abs(4 * i - 4 * j - 2);
			tot += dx * dx * a[j];
		}
		ret = min(ret, make_pair(tot, i));
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			a[i] += x;
			b[j] += x;
		}
	}
	auto p1 = solve(a, n);
	auto p2 = solve(b, m);
	printf("%lld\n", p1.first + p2.first);
	printf("%d %d\n", p1.second, p2.second);
	return 0;
}