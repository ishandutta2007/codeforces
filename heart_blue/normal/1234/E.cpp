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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
int a[N];
int pos[N];
int b[N];
vector<int> v[N];
LL ans = 0;
int n, m;
int flag = 0;
void change(int x, int val)
{
	if (x == 1 || x == 2 * m)
	{
		a[x] = val;
		return;
	}

	ans -= abs(a[x] - a[x ^ 1]);
	a[x] = val;
	ans += abs(a[x] - a[x ^ 1]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		b[i] = pos[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		a[i * 2 - 1] = x;
		a[i * 2] = x;
		v[x].push_back(i * 2 - 1);
		v[x].push_back(i * 2);
	}
	ans = 0;
	for (int i = 3; i <= 2 * m; i += 2)
	{
		ans += abs(a[i] - a[i - 1]);
	}
	printf("%lld ", ans);
	for (int i = 2; i <= n; i++)
	{
		swap(b[i], b[1]);
		pos[b[1]] = 1;
		pos[b[i]] = i;
		for (auto& x : v[b[1]])
			change(x, 1);
		for (auto& x : v[b[i]])
			change(x, i);
		printf(" %lld", ans);
	}
	return 0;
}