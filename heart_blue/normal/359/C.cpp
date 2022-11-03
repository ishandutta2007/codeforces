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
LL a[N];
LL powmod(LL a, LL b, LL mod = INF)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, p;
	cin >> n >> p;
	LL tot = 0;
	LL ans = 0;
	LL minv = INF*INF;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		tot += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = tot - a[i];
		minv = min(minv, a[i]);
	}
	for (int i = 0; i < n; i++) a[i] -= minv;
	ans = minv;
	map<LL, int> mc;
	for (int i = 0; i < n; i++)
	{
		int x = a[i];
		mc[x]++;
		while (mc[x] == p)
		{
			mc[x] = 0;
			mc[x + 1]++;
			x++;
		}
	}
	for (auto &p : mc)
	{
		if (p.second == 0) continue;
		ans += p.first;
		break;
	}
	ans = min(ans, tot);
	cout << powmod(p, ans) << endl;
	return 0;
}