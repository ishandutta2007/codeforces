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
const int N = 2e2 + 10;
LL add(LL x, LL y)
{
	if (x + y >= INF * INF) return INF * INF;
	else return x + y;
}
LL dp[N][N];
LL key[N];
LL tot[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL k;
	cin >> n >> k;
	string str;
	cin >> str;
	for (auto& c : str)
	{
		MEM(key, 0);
		for (int i = 'a'; i <= 'z'; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				key[j + 1] = add(key[j + 1], dp[i][j]);
			}
		}
		key[1] = 1;
		for (int i = 1; i <= n; i++)
			dp[c][i] = key[i];
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		for (int i = 1; i <= n; i++)
		{
			tot[i] = add(tot[i], dp[c][i]);
		}
	}
	LL ans = 0;
	tot[0] = 1;
	for (int i = n; i >= 0; i--)
	{
		LL o = min(k, tot[i]);
		ans += o * (n - i);
		k -= o;
	}
	if (k > 0) ans = -1;
	printf("%lld\n", ans);
	return 0;
}