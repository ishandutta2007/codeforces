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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
const int b = 131;
const LL mod = 998244353;
LL p[N];
LL rp[N];
char s1[N], s2[N];
LL sum[N];
LL powmod(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
void init()
{
	p[0] = 1;
	for (int i = 1; i < N; i++)
		p[i] = p[i - 1] * b % mod;
	rp[0] = 1;
	int rb = powmod(b, mod - 2);
	for (int i = 1; i < N; i++)
		rp[i] = rp[i - 1] * rb % mod;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	int n = strlen(s1 + 1);
	int m = strlen(s2 + 1);
	int cnt0 = count(s1 + 1, s1 + n + 1, '0');
	int cnt1 = n - cnt0;
	for (int i = 1; i <= m; i++)
	{
		sum[i] = (s2[i] * p[i] + sum[i - 1]) % mod;
	}
	int ans = 0;
	for (int i = 1; i * cnt0 <= m; i++)
	{
		int rest = m - i * cnt0;
		if (cnt1 == 0)
		{
			if (rest != 0)
				continue;
		}
		else if (rest == 0 || rest % cnt1)
			continue;
		int j = rest / cnt1;
		int ok = 1;
		int cur = 1;
		int len[2] = { i,j };
		LL key[2] = { -1,-1 };
		int ptr = 1;
		while (cur <= m)
		{
			int o = s1[ptr++] - '0';
			int l = cur;
			int r = cur + len[o] - 1;
			LL h = (sum[r] - sum[l - 1]) * rp[l] % mod;
			if (h < 0) h += mod;

			cur = r + 1;
			if (key[o] == -1)
			{
				key[o] = h;
				continue;
			}
			if (key[o] != h)
			{
				ok = 0;
				break;
			}
		}
		if (len[0] == len[1] && key[0] == key[1])
			ok = 0;
		ans += ok;
		if (cnt0 == 0) break;
	}
	printf("%d\n", ans);
	return 0;
}