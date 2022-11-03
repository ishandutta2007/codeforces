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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int dfn[N];
int low[N];
int instack[N];
int s[N];
int top = 0;
int scccnt = 0;
int cnt = 1;
int minv[N];
int sz[N];
int w[N];
void tarjan(int x, int fa = -1)
{
	instack[x] = 1;
	s[top++] = x;
	low[x] = dfn[x] = cnt++;
	for (auto &y : v[x])
	{
		if (dfn[y])
		{
			if (instack[y]) low[x] = min(low[x], dfn[y]);
		}
		else
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
		}
	}
	if (dfn[x] == low[x])
	{
		int &m = minv[scccnt] = INF;
		int &c = sz[scccnt] = 0;
		while (1)
		{
			int y = s[--top];
			instack[y] = 0;
			if (m > w[y]) m = w[y], c = 0;
			if (m == w[y]) c++;
			if (x == y) break;
		}
		scccnt++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(dfn, 0);
	MEM(instack, 0);
	for (int i = 1; i <= n; i++) cin >> w[i];
	int m;
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (dfn[i] == 0)
			tarjan(i);
	}
	LL sum = 0;
	LL ans = 1;
	for (int i = 0; i < scccnt; i++)
	{
		sum += minv[i];
		ans = (ans*sz[i]) % INF;
	}
	cout << sum << ' ' << ans << endl;
	return 0;
}