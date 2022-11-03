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
const int N = 6e1 + 10;
const int mod = 998244353;
LL a[N][N];
LL ans1[N];
LL ans2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < N; i++)
		a[i][0] = a[i][i] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < i; j++)
			a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % mod;
	}
	for (int i = 2; i < N; i += 2)
	{
		ans1[i] = (a[i - 1][i / 2] + ans2[i - 2]) % mod;
		ans2[i] = (a[i][i / 2] - ans1[i] - 1) % mod;
		if (ans2[i] < 0) ans2[i] += mod;
	}
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld %lld 1\n", ans1[n], ans2[n]);
	}
	return 0;
}