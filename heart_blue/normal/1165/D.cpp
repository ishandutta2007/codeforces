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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int flag[N];
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
void init()
{
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		for (int j = i + i; j < N; j += i) flag[j] = 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	init();
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (auto &x : v) scanf("%d", &x);
		sort(v.begin(), v.end());
		if (flag[v.front()])
		{
			puts("-1");
			continue;
		}
		LL g = 0;
		LL lcm = 1;
		LL maxv = 1e12;
		int tot = 0;
		for (auto &x : v)
		{
			tot += flag[x] ^ 1;
			g = gcd(lcm, x);
			lcm *= x / g;
			if (lcm >= maxv)
			{
				break;
			}
		}
		if (lcm >= maxv)
		{
			puts("-1");
			continue;
		}
		sort(v.begin(), v.end());
		if (tot == 1) lcm *= v.front();
		if (lcm >= maxv)
		{
			puts("-1");
			continue;
		}
		vector<LL> v2;
		for (LL i = 2; i * i <= lcm; i++)
		{
			if (lcm%i) continue;
			v2.push_back(i);
			if (lcm / i != i) v2.push_back(lcm / i);
		}
		sort(v2.begin(), v2.end());
		if (v.size() != v2.size())
		{
			puts("-1");
			continue;
		}
		else
		{
			LL ans = lcm;
			for (int i = 0; i < n; i++)
			{
				if (v[i] != v2[i])
				{
					ans = -1;
					break;
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}