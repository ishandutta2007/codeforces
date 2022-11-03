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
#define MEM(a,b) memset((a),(vp),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int mod;
map<int, int> mc[100];
LL p[100];
int a[N];
int getcnt(int x)
{
	int cnt = 0;
	while (x)
	{
		cnt++;
		x /= 10;
	}
	return cnt;
}
void check(int x)
{
	int cnt = getcnt(x);
	int res = x % mod;
	mc[cnt][res]++;
}
int refrain(int x)
{
	return (x*p[getcnt(x)] % mod + x) % mod == 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d%d", &n, &mod);
	p[0] = 1;
	for (int i = 1; i < 100; i++) p[i] = 10LL * p[i - 1] % mod;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		check(x);
		a[i] = x;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			int o = mod - a[i] * p[j] % mod;
			if (o == mod) o = 0;
			if (mc[j].count(o)) ans += mc[j][o];
		}
		ans -= refrain(a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}