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
int flag[10];
int cnt[10];
int solve(int n)
{
	int ret = 0;
	MEM(flag, 0);
	MEM(cnt, 0);
	while (cnt[n] == 0)
	{
		int f = 1;
		for (int i = 0; i < n; i++)
		{
			int tot = n;
			int o = i;
			f = 0;
			while (tot--)
			{
				o = cnt[o];
				if (o == 0)
				{
					f = 1;
					break;
				}
			}
			if (f == 0) break;
		}
		ret += f;
		cnt[0]++;
		for (int i = 0; i < n; i++)
		{
			if (cnt[i] == n) cnt[i] = 0, cnt[i + 1]++;
		}
	}
	return ret;
}
LL powmod(int a, int b, int mod = INF)
{
	LL ret = 1;
	LL o = a;
	while (b)
	{
		if (b & 1) ret = ret*o%mod;
		o = o*o%mod;
		b >>= 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	n -= k;
	cout << powmod(n,n)*solve(k)%INF << endl;
	return 0;
}