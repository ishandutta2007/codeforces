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
const int N = 5e5 + 10;
LL powmod(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % INF;
		b >>= 1;
		a = a * a % INF;
	}
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, p;
		scanf("%d%d", &n, &p);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		if (p == 1)
		{
			printf("%d\n", n & 1);
			continue;
		}
		sort(v.begin(), v.end());
		LL ans = 0;
		while (!v.empty())
		{
			int x = v.back();
			int key = x;
			int cur = 1;
			v.pop_back();
			for (int i = v.size() - 1; i >= 0; i--)
			{
				int y = v[i];
				while (x > y && cur <= 1e6)
				{
					x--;
					cur = cur * p;
				}
				if (cur > 1e6) break;
				cur--;
				if (cur == 0)
				{
					while (i < v.size()) v.pop_back();
					break;
				}
			}
			if (cur == 0) continue;
			ans = powmod(p, key);
			for (auto& y : v)
				ans -= powmod(p, y);
			ans %= INF;
			if (ans < 0) ans += INF;
			break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}