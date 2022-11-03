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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<LL> a(n), b(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] *= 1LL*(i + 1)*(n - i);
	}
	for (auto &x : b) scanf("%lld", &x);
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	const int mod = 998244353;
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += a[i] % mod*b[i] % mod;
	}
	printf("%lld\n", ans%mod);
	return 0;
}