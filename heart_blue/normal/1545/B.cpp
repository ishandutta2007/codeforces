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
const int N = 2e5 + 10;
const int MOD = 998244353;
LL fact[N];
LL rfact[N];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = i * fact[i - 1] % MOD;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++)
		rfact[i] = (MOD - MOD / i) * rfact[MOD % i] % MOD;
	for (int i = 2; i < N; i++)
		rfact[i] = rfact[i] * rfact[i - 1] % MOD;
}
LL C(int n, int m)
{
	return fact[n] * rfact[m] % MOD * rfact[n - m] % MOD;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		string str;
		int cnt0 = 0;
		int cnt1 = 0;
		cin >> n >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '0') cnt0++;
			else if (i + 1 < str.length())
			{
				if (str[i + 1] == '1') cnt1++, i++;
			}
		}
		printf("%lld\n", C(cnt1 + cnt0, cnt0));
	}
	return 0;
}