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
const int N = 5e2 + 10;
LL a[N];
vector<LL> v[N];
map<LL, int> mc;
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
LL check(LL n, int o)
{
	LL x = pow(n, 1.0 / o) + 0.5;
	LL tot = 1;
	while (o--) tot *= x;
	if (tot == n) return x;
	else return -1;
}
void check(int o, LL x)
{
	if (!v[o].empty()) return;
	LL tot = a[o];
	while (tot % x == 0) v[o].push_back(x), tot /= x;
	if (tot > 1) v[o].push_back(tot);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int o = 4; o >= 2; o--)
		{
			LL x = check(a[i], o);
			if (x == -1) continue;
			LL tot = a[i];
			while (tot % x == 0) v[i].push_back(x), tot /= x;
			break;
			/*for (int j = 1; j <= n; j++)
			{
				if (!v[j].empty()) continue;
				if (i == j) continue;
				if (a[j] % x == 0)
				{
					LL tot = a[j];
					while (tot % x == 0) v[j].push_back(tot), tot /= x;
					if (tot > 1) v[j].push_back(tot);
				}
			}*/
		}
	}
	map<LL, int> mc2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] == a[j]) continue;
			LL g = gcd(a[i], a[j]);
			if (g == 1) continue;
			check(i, g);
			check(j, g);
		}
	}
	LL ans = 1;
	const int MOD = 998244353;
	for (int i = 1; i <= n; i++)
	{
		for (auto &x : v[i]) mc[x]++;
		if (v[i].empty()) mc2[a[i]]++;
	}
	for (auto &p : mc)
	{
		ans = ans * (p.second + 1) % MOD;
	}
	for (auto &p : mc2)
	{
		ans = ans * (p.second + 1) % MOD*(p.second + 1) % MOD;
	}
	cout << ans << endl;
	return 0;
}