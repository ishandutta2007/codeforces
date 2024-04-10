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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, k, p;
	cin >> n >> k >> p;
	if (k == 0 || k == n)
	{
		while (p--)
		{
			putchar(".X"[k == n]);
		}
		return 0;
	}
	if (n & 1) k--, n--;
	vector<pair<LL, string>> vp;
	if (k * 2 <= n)
	{
		vp.emplace_back(n / 2 - k, "..");
		vp.emplace_back(k, ".X");
	}
	else
	{
		vp.emplace_back(n - k, ".X");
		vp.emplace_back(k - n / 2, "XX");
	}
	while (p--)
	{
		LL x;
		scanf("%lld", &x);
		if (x > n)
		{
			putchar('X');
			continue;
		}
		for (auto& p : vp)
		{
			LL tot;
			string str;
			tie(tot, str) = p;
			if (x <= tot*2)
			{
				putchar(str[(x - 1) % 2]);
				break;
			}
			else
			{
				x -= tot * 2;
			}
		}
	}
	return 0;
}