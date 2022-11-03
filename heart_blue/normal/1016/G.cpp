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
const int N = 1e6 + 10;
vector<LL> p;
vector<LL> pp;
LL check(LL &r)
{
	LL ret = 1;
	for (LL i = 2; i * i <= r && i <= N; i++)
	{
		if (r%i) continue;
		while (r%i == 0) r /= i, ret *= i;
		p.push_back(i);
	}
	if (r < 1LL * N*N && r != 1)
	{
		p.push_back(r);
		ret *= r;
		r = 1;
	}
	return ret;
}
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
void refrain(map<LL, int> &mc)
{
	vector<LL> v;
	for (auto &p : mc) v.push_back(p.first);
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			LL g = gcd(v[i], v[j]);
			if (!mc.count(g))
			{
				if (g != 1)
				{
					v.push_back(g);
					mc[g] = 1;
				}
			}
			if (v[i] % v[j] == 0)
			{
				LL x = v[i] / v[j];
				if (!mc.count(x))
				{
					if (x != 1)
					{
						v.push_back(x);
						mc[x] = 1;
					}
				}
			}
			if (v[j] % v[i] == 0)
			{
				LL x = v[j] / v[i];
				if (!mc.count(x))
				{
					if (x != 1)
					{
						v.push_back(x);
						mc[x] = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (i != j && v[i] % v[j] == 0) mc.erase(v[i]);
		}
	}
	for (auto &p : mc) ::p.push_back(p.first);
}
void recheck(LL n)
{
	for (auto &x : p)
	{
		LL o = 1;
		while (n % x == 0) n /= x, o *= x;
		pp.push_back(o);
	}
}
vector<LL> v1, v2;
LL cnt1[N];
LL cnt2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL X, Y;
	cin >> n >> X >> Y;
	if (Y%X)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		LL x;
		cin >> x;
		if (x%X == 0) v1.push_back(x);
		if (Y%x == 0) v2.push_back(x);
	}
	LL r = Y;
	LL o = check(r);
	//for (auto &x : v1) x = gcd(x, Y);
	map<LL, int> mc;
	for (auto x : v1)
	{
		x = gcd(x, Y);
		LL oo = x / gcd(x, o);
		if (oo > 1) mc[oo] = 1;
	}
	refrain(mc);
	recheck(Y);
	for (auto &x : v2)
	{
		LL t = 1;
		for (auto &xx : pp)
		{
			if (x%xx) t *= xx;
		}
		t = t / gcd(t, X);
		int o = 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (t%p[i] == 0)
				o |= 1 << i;
		}
		cnt1[o]++;
	}
	int mask = (1 << p.size()) - 1;
	for (int i = 0; i <= mask; i++)
	{
		for (int j = i; j; j = (j - 1)&i)
		{
			cnt2[i] += cnt1[j];
		}
		cnt2[i] += cnt1[0];
	}
	LL ans = 0;
	for (auto &x : v1)
	{
		x /= X;
		int o = 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (x%p[i] == 0)
				o |= 1 << i;
		}
		ans += cnt2[mask^o];
	}
	printf("%lld\n", ans);
	return 0;
}