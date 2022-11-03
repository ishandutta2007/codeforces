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
const int N = 1e4 + 10;
map<int, int> mc;
int dfs(int x)
{
	if (x <= 2) return x;
	//if (mc1.count(x)) return mc1[x];
	if (x & 1)
	{
		return 0;
		/*return mc1[x] = (dfs(x - 1) == 0);*/
	}
	else
	{
		return 1;
		/*return mc1[x] = (dfs(x - 1) == 1 ? 2 : 1);*/
	}
}
int dfs2(int x)
{
	if (x <= 3) return x & 1;
	if (mc.count(x)) return mc[x];
	if (x & 1)
	{
		return 0;
	}
	else
	{
		int mex[10];
		MEM(mex, 0);
		mex[dfs2(x - 1)] = 1;
		mex[dfs2(x >> 1)] = 1;
		int &ret = mc[x];
		for (int i = 0; i < 10; i++)
		{
			ret = i;
			if (mex[i] == 0) break;
		}
		return ret;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (k & 1) ans ^= dfs2(x);
		else ans ^= dfs(x);
	}
	if (ans) puts("Kevin");
	else puts("Nicky");
	return 0;
}
/*
0 0
1 1
2 0
3 1
4 2
*/