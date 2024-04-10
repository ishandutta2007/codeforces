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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
int a[N];
set<int> s;
map<int, int> mc;
void add(map<int, int>& mc, int x)
{
	mc[x]++;
}
void del(map<int, int>& mc, int x)
{
	mc[x]--;
	if (mc[x] == 0)
		mc.erase(x);
}
void add(int x)
{
	auto iter = s.lower_bound(x);
	int r = INF;
	if (iter != s.end()) r = *iter;
	int l = -INF;
	if (iter != s.begin())
	{
		iter--;
		l = *iter;
	}
	if (r != INF && l != -INF)
	{
		del(mc, r - l);
	}
	s.insert(x);
	if (r != INF) add(mc, r - x);
	if (l != -INF) add(mc, x - l);
}
void del(int x)
{
	auto iter = s.upper_bound(x);
	int r = INF;
	if (iter != s.end()) r = *iter;
	int l = -INF;
	iter--;
	if (iter != s.begin())
	{
		iter--;
		l = *iter;
	}
	if (r != INF && l != -INF)
	{
		add(mc, r - l);
	}
	s.erase(x);
	if (r != INF) del(mc, r - x);
	if (l != -INF) del(mc, x - l);
}
void getans()
{
	if (s.size() <= 2)
	{
		puts("0");
		return;
	}
	printf("%d\n", *s.rbegin() - *s.begin() - mc.rbegin()->first);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		add(a[i]);
	}
	getans();
	while (q--)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		if (op == 1)
		{
			add(x);
		}
		else
		{
			del(x);
		}
		getans();
	}

	return 0;
}