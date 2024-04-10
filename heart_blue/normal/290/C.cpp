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
const int N = 2e5 + 30;
ULL a, b;
int dp[N][2];
int d[N];
int dfs(int pos = 63, int carry = 0, bool limit = true)
{
	if (pos == -1)
	{
		return carry == 0;
	}
	if (!limit && dp[pos][carry] != -1) return dp[pos][carry];
	int up = 1;
	if (limit) up = d[pos];
	int ret = 0;
	for (int o1 = 0; o1 <= d[pos]; o1++)
	{
		int o2 = ((b >> pos) & 1) ^ o1;
		for (int j = 0; j < 2; j++)
		{
			if ((o1 ^ o2 ^ j) != (a >> pos & 1)) continue;
			if (carry ^ (o1 + o2 + j < 2))
			{
				ret |= dfs(pos - 1, j, limit && o1 == d[pos]);
			}
		}
	}
	if (!limit)
		dp[pos][carry] = ret;
	return ret;
}
bool solve(ULL x)
{
	for (int i = 0; i <= 63; i++)
		d[i] = x >> i & 1;
	return dfs();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int foo = 0, bar = 0, baz = 0, quz = 1;
	for (int i = 0; i < n; i++) {
		int pur;
		cin >> pur;
		foo += pur;
		bar++;
		if (foo * quz > baz* bar) {
			baz = foo;
			quz = bar;
		}
	}
	cout << 1.0 * baz / quz << endl;
	return 0;
}