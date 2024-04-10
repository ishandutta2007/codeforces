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
const int N = 5e3 + 10;
const int mod = 998244353;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < N; i++) a[i][i] = a[i][0] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			if (a[i][j] >= mod)
				a[i][j] -= mod;
		}
	}
	int n, m, k;
	cin >> n >> m >> k;
	LL ans = a[n - 1][k] * 1LL * m % mod;
	while (k--)
		ans = ans * (m - 1) % mod;
	cout << ans << endl;
	return 0;
}