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
const int N = 1e6 + 10;
bool check(LL d, LL n, LL k)
{
	return k*(k + 1) / 2 <= n / d;
}
void solve(LL d, LL n, LL k)
{
	n /= d;
	for (int i = 1; i < k; i++)
	{
		cout << i * d << ' ';
		n -= i;
	}
	cout << n * d << endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, k;
	cin >> n >> k;
	if (k > N)
	{
		puts("-1");
		return 0;
	}
	LL o = 0;
	for (LL i = 1; i * i <= n; i++)
	{
		if (n%i) continue;
		if (check(i, n, k))
		{
			o = max(o, i);
		}
		if (check(n / i, n, k))
		{
			o = max(o, n / i);
		}
	}
	if (o) solve(o, n, k);
	else puts("-1");
	return 0;
}