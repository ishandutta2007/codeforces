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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int low[N], dfn[N], cnt;
int instack[N], s[N], top;
vector<int> v[N];
LL ans = 1;
int tot;
LL powmod(int a, int b, int mod = INF)
{
	LL ret = 1;
	LL t = a;
	while (b)
	{
		if (b & 1) ret = ret*t%INF;
		t = t*t%INF;
		b >>= 1;
	}
	return ret;
}

void tarjan(int x, int p = -1)
{
	low[x] = dfn[x] = cnt++;
	instack[x] = 1;
	s[top++] = x;
	int flag = 0;
	for (auto &y : v[x])
	{
		if (y == p && !flag)
		{
			flag = 1;
			continue;
		}
		if (dfn[y]) low[x] = min(low[x], dfn[y]);
		else
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
		}
	}
	if (dfn[x] == low[x])
	{
		int c = 0;
		while (1)
		{
			int y = s[--top];
			instack[y] = 0;
			c++;
			if (x == y) break;
		}
		if (c != 1)
		{
			ans *= powmod(2, c) - 2;
			ans %= INF;
			if (ans < 0) ans += INF;
			tot -= c;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[i].push_back(x);
		v[x].push_back(i);
	}
	MEM(instack, 0);
	MEM(dfn, 0);
	cnt = 0;
	top = 0;
	tot = n;
	for (int i = 1; i <= n; i++)
	{
		if(!dfn[i])
			tarjan(i);
	}
	ans = ans*powmod(2, tot) % INF;
	cout << ans << endl;
	return 0;
}