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
const int N = 4e5 + 10;
const int MOD = 998244353;
LL f[N];
LL rf[N];
void init()
{
	f[0] = 1;
	for (int i = 1; i < N; i++) f[i] = i * f[i - 1] % MOD;
	rf[0] = rf[1] = 1;
	for (int i = 2; i < N; i++) rf[i] = (MOD - MOD / i) * rf[MOD % i] % MOD;
	for (int i = 2; i < N; i++) rf[i] = rf[i - 1] * rf[i] % MOD;
}

LL C(int n, int m)
{
	return f[n] * rf[m] % MOD * rf[n - m] % MOD;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	LL ans = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 2; i < n; i++)
	{
		ans += C(n - 2, i - 1) * (i - 1) % MOD;
	}
	ans = ans % MOD * C(m, n - 1) % MOD;
	cout << ans << endl;
	return 0;
}