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
const int N = 5e3 + 10;
const int MOD = 998244353;
LL fact[N];
LL c[N][N];
void init()
{
	for (int i = 0; i < N; i++) c[i][i] = c[i][0] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= MOD) c[i][j] -= MOD;
		}
	}
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
}
LL getans(LL a, LL b)
{
	LL ans = 0;
	for (int i = 0; i <= min(a, b); i++)
	{
		ans = (ans + c[a][i] * c[b][i] % MOD*fact[i]) % MOD;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	LL a, b, c;
	cin >> a >> b >> c;
	cout << getans(a, b)*getans(b, c) % MOD*getans(a, c) % MOD << endl;
	return 0;
}