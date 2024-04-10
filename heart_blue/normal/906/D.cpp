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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> v;
map<int, int> phi;
int a[N];
int l, r;
LL mypow(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (a > INF) return INF;
		if (b & 1) ret = ret * a;
		if (ret > INF) return INF;
		a = a*a;
		b >>= 1;
	}
	return min(ret, INF);
}
LL powmod(LL a, LL b, LL mod)
{
	LL ret = 1 % mod;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		a = a*a %mod;
		b >>= 1;
	}
	return ret;
}
LL check(int l, int r)
{
	vector<int> vv;
	for (int i = l; i <= r; i++)
	{
		if (a[i] == 1) break;
		vv.push_back(a[i]);
	}
	if (vv.empty()) return 1;
	LL b = vv.back();
	vv.pop_back();
	while (!vv.empty()) b = mypow(vv.back(), b), vv.pop_back();
	return b;
}
int getphi(int n)
{
	int ans = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n%i) continue;
		ans = ans / i*(i - 1);
		while (n%i == 0) n /= i;
	}
	if (n > 1) ans = ans / n*(n - 1);
	return ans;
}
void check(int n)
{
	v.push_back(n);
	while (n > 1)
	{
		int tmp = getphi(n);
		phi[n] = tmp;
		n = tmp;
		v.push_back(n);
	}
	v.push_back(1);
}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
LL solve(int cur, int modpos)
{
	int mod = v[modpos];
	if (mod == 1) return 1;
	if (cur > r) return 1;
	{
		LL b = check(cur + 1, min(cur + 6, r));
		if (b < v[modpos + 1])
		{
			return powmod(a[cur], b, mod);
		}
		else
		{
			LL ret = powmod(a[cur], solve(cur + 1, modpos + 1) + v[modpos + 1], mod);
			return ret;
		}
	}

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	check(m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d", &l, &r);
		printf("%lld\n", solve(l, 0) % m);
	}
	return 0;
}