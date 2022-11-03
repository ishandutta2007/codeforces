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
const LL INF = 1e6 + 3;
const int N = 2e6 + 10;

int getans(int x, int y)
{
	LL ret = 1;
	for (int i = 30; i >= 0; i--)
	{
		ret = ret *ret%INF;
		if (y&(1 << i))
		{
			ret = ret*x%INF;
		}
		ret %= INF;
	}
	return ret;
}

LL fact(int n)
{
	LL ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret = (ret*i) % INF;
	}
	return ret;
}

int inv(int n)
{
	return getans(n, INF - 2);
}
int solve(int n, int m)
{
	int a = fact(n);
	int b = fact(m);
	int c = fact(n - m);
	LL rb = inv(b);
	LL rc = inv(c);
	return a * rb %INF*rc%INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ans = solve(n + m, n) - 1;
	if (ans < 0) ans += INF;
	cout << ans << endl;
	return 0;
}