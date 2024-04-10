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
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL l, r, x, y;
	cin >> l >> r >> x >> y;
	if (y%x)
	{
		cout << 0 << endl;
		return 0;
	}
	y /= x;
	vector<LL> v;
	int ans = 0;
	for (LL i = 1; i *i <= y; i++)
	{
		if (y%i) continue;
		LL a = i;
		LL b = y / i;
		if (a*x < l || a * x > r) continue;
		if (b*x < l || b * x > r) continue;
		if (gcd(a, b) == 1) ans += 1 + (a != b);
	}
	cout << ans << endl;
	return 0;
}