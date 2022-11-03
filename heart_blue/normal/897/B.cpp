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
const int N = 2e5 + 10;
LL check(LL n)
{
	LL x = n;
	LL ret = 0;
	while (x)
	{
		n *= 10;
		ret *= 10;
		ret += x % 10;
		x /= 10;
	}
	return ret + n;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += check(i);
		ans %= q;
	}
	cout << ans << endl;
	return 0;
}