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
const int N = 2e5 + 10;
vector<int> v[4];
void check(int a, int b, int x, int y)
{
	if (a < b) swap(a, b), swap(x, y);
	if (a > b + 1) puts("NO"), exit(0);
	puts("YES");
	while (a || b)
	{
		printf("%d ", x);
		a--;
		swap(a, b);
		swap(x, y);
	}
	exit(0);
}
void check(int a, int b, int c, int x, int y, int z)
{
	if (a == 0) check(b, c, y, z);
	if (c == 0) check(a, b, x, y);
	if (b == 0) puts("NO"), exit(0);
	if (b >= a + c - 1 && b <= a + c + 1)
	{
		puts("YES");
		if (b == a + c - 1) printf("%d ", x), a--;
		b -= a + c;
		while (a--) printf("%d %d ", y, x);
		while (c--) printf("%d %d ", y, z);
		if (b) printf("%d ", y);
	}
	else puts("NO");
	exit(0);
}
void solve(int a, int b, int c, int d,
	int x = 0, int y = 1, int z = 2, int w = 3)
{
	if (a == 0) check(b, c, d, y, z, w);
	if (d == 0) check(a, b, c, x, y, z);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	solve(a, b, c, d);
	if (a > b + 1) puts("NO"), exit(0);
	if (d > c + 1) puts("NO"), exit(0);
	b -= a - 1;
	c -= d - 1;
	for (int i = 1; i <= a; i++)
	{
		v[0].push_back(0);
		v[0].push_back(1);
		if (i == a) v[0].pop_back();
	}
	for (int i = 1; i <= d; i++)
	{
		v[3].push_back(3);
		v[3].push_back(2);
		if (i == d) v[3].pop_back();
	}
	if (b == 0 || c == 0 || abs(b - c) > 1) puts("NO"), exit(0);
	puts("YES");
	while (b > 0 && c > 0)
	{
		b--, c--;
		v[1].push_back(1);
		v[1].push_back(2);
	}
	if (b) v[0].insert(v[0].begin(), 1);
	if (c) v[3].push_back(2);
	for (int i = 0; i < 4; i++)
	{
		for (auto& x : v[i]) cout << x << ' ';
	}
	return 0;
}