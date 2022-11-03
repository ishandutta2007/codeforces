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
const int N = 3e5 + 10;
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, k;
	cin >> n >> k;
	int a, b;
	cin >> a >> b;
	vector<int> v;
	v.push_back(a);
	v.push_back(int(k) - a);
	LL maxv = 0, minv = INF * INF;
	for (auto& x : v)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = -1; j <= 1; j += 2)
			{
				LL cur = 1LL * i * k + b * j;
				LL d = x - cur;
				d %= 1LL * n * k;
				if (d < 0) d += 1LL * n * k;
				LL g = 1LL * n * k / gcd(1LL * n * k, d);
				minv = min(minv, g);
				maxv = max(maxv, g);
			}
		}
	}
	printf("%lld %lld\n", minv, maxv);
	return 0;
}