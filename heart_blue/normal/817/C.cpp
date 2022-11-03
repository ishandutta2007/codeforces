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
const int N = 2e2 + 10;
int sum(LL x)
{
	int ret = 0;
	while (x)
	{
		ret += x % 10;
		x /= 10;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, s;
	cin >> n >> s;
	int cnt = 1e4;
	LL ans = 0;
	LL x = min(s, n + 1);
	while (cnt--)
	{
		if (x > n) break;
		if (x - sum(x) >= s) ans++;
		x++;
	}
	cout << ans + n - x + 1 << endl;
	return 0;
}