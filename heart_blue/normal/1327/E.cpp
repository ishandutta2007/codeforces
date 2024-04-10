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
const int MOD = 998244353;
LL p[N];
LL ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	p[0] = 1;
	for (int i = 1; i < N; i++) p[i] = 10 * p[i - 1] % MOD;
	int n;
	cin >> n;
	for (int i = 1; i + 2 <= n; i++)
	{
		ans[i] = 10 * 9 * 9 * p[n - i - 2] * (n - i - 1);
	}
	for (int i = 1; i < n; i++)
	{
		ans[i] += 2 * 10 * 9 * p[n - i - 1];
	}
	ans[n] = 10;
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] % MOD << ' ';
	}
	return 0;
}