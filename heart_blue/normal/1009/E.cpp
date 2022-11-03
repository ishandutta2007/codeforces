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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
const LL mod = 998244353;
LL a[N];
LL b[N];
LL p[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	p[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] << 1;
		if (p[i] >= mod) p[i] -= mod;
	}
	
	LL ans = 0;
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i <= 2) sum = (sum + a[i]) % mod;
		else sum = (a[i] + sum * 2 - a[i - 1]) % mod;
		if (sum < 0) sum += mod;
		ans = (ans + sum * p[n - i]) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}