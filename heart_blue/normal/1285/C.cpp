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
const int N = 2e5 + 10;
int a[N];
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
LL check(LL n)
{
	LL ans = n;
	for (int i = 1; 1LL * i * i <= n; i++)
	{
		if (n % i) continue;
		if (gcd(i, n / i) > 1) continue;
		ans = min(ans, n / i);
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	cin >> n;
	cout << check(n) << ' ' << n / check(n) << endl;
	return 0;
}