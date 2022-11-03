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
vector<int> v[N];
int val[N];
char op[N];
int flag[N];
int init(int x)
{
	if (::op[x] == 'I') return val[x];
	int ret[2] = { 0,0 };
	int o = 0;
	for (auto &y : v[x])
	{
		ret[o++] = init(y);
	}
	char op = ::op[x];
	if (op == 'A')
	{
		val[x] = ret[0] & ret[1];
	}
	else if (op == 'X')
	{
		val[x] = ret[0] ^ ret[1];
	}
	else if (op == 'O')
	{
		val[x] = ret[0] | ret[1];
	}
	else if (op == 'N')
	{
		val[x] = ret[0] ^ 1;
	}
	return val[x];
}
void dfs(int x)
{
	if (op[x] == 'I')
	{
		flag[x] = 1;
		return;
	}
	int s1 = 0, s2 = 0;
	s1 = v[x].front();
	s2 = v[x].back();
	if (op[x] == 'A')
	{
		if (val[x] == 1)
		{
			dfs(s1);
			dfs(s2);
		}
		else if (val[s1] != val[s2])
		{
			if (val[s1] == 0) dfs(s1);
			else dfs(s2);
		}

	}
	else if (op[x] == 'X')
	{
		dfs(s1);
		dfs(s2);
	}
	else if (op[x] == 'N')
	{
		dfs(s1);
	}
	else if (op[x] == 'O')
	{
		if (val[x] == 0)
		{
			dfs(s1);
			dfs(s2);
		}
		else if (val[s1] != val[s2])
		{
			if (val[s1]) dfs(s1);
			else dfs(s2);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	char str[10];
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		int x, y;
		x = y = 0;
		op[i] = str[0];
		if (str[0] == 'I' || str[0] == 'N') scanf("%d", &x);
		else scanf("%d%d", &x, &y);
		if (str[0] == 'I')
		{
			val[i] = x;
			continue;
		}
		v[i].push_back(x);
		if (y) v[i].push_back(y);
	}
	int ans = init(1);
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		if (op[i] != 'I') continue;
		putchar((ans^flag[i]) + '0');
	}
	return 0;
}