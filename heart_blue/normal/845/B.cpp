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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int sum(int x)
{
	int ret = 0;
	while (x)
	{
		ret += x % 10;
		x /= 10;
	}
	return ret;
}
int getans(int x, int y)
{
	int ret = 0;
	while (x != 0 || y != 0)
	{
		if (x % 10 != y % 10) ret++;
		x /= 10;
		y /= 10;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ans = 6;
	int n;
	cin >> n;
	for (int i = 0; i < 1000000; i++)
	{
		if (sum(i / 1000) != sum(i % 1000)) continue;
		ans = min(ans, getans(i / 1000, n / 1000) + getans(i % 1000, n % 1000));
	}
	cout << ans << endl;
	return 0;
}