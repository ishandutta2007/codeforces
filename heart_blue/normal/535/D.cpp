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
const int N = 1e6 + 10;
char str[N];
int flag[N];
int fail[N];
void getfail(int n)
{
	int j = 0;
	fail[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		while (j > 0 && str[j + 1] != str[i]) j = fail[j];
		if (str[j + 1] == str[i]) j++;
		fail[i] = j;
	}
	while (fail[n])
	{
		n = fail[n];
		flag[n] = 1;
	}
}
LL powmod(LL a, LL b, LL mod = INF)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		a = a * a%mod;
		b >>= 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", str + 1);
	int len = strlen(str + 1);
	getfail(len);
	vector<int> v(k);
	for (auto &x : v) scanf("%d", &x);
	int cur = 0;
	for (int i = 0; i < k; i++)
	{
		if (i != 0)
		{
			int d = len - (v[i] - v[i - 1]);
			if (d > 0 && !flag[d])
			{
				puts("0");
				return 0;
			}
		}
		cur = max(cur, v[i]);
		n -= v[i] + len - 1 - cur + 1;
		cur = v[i] + len;
	}
	printf("%lld\n", powmod(26, n));
	return 0;
}