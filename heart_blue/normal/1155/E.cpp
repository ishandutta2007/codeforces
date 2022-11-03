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
#include <regex>
#include <valarray>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
const LL MOD = 1e6 + 3;
valarray<LL> a[20];
LL powmod(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ret;
}
void solve(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[j][i])
			{
				swap(a[i], a[j]);
				break;
			}
		}
		if (a[i][i] < 0) a[i] *= -1;
		LL r = powmod(a[i][i], MOD - 2);
		a[i] *= r;
		a[i] %= MOD;
		for (int j = i + 1; j < n; j++)
		{
			a[j] -= a[j][i] * a[i];
			a[j] %= MOD;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			a[j] -= a[j][i] * a[i];
			a[j] %= MOD;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 11;
	for (int i = 0; i < 11; i++)
	{
		cout << "? " << i << endl;
		a[i].resize(12, 0);
		cin >> a[i][11];
		for (int j = 0; j < 11; j++)
		{
			a[i][j] = powmod(i, j);
		}
	}
	solve(n);
	vector<LL> v;
	for (int i = 0; i < n; i++)
		v.push_back(a[i][11]);
	reverse(v.begin(), v.end());
	for (int x = 0; x < MOD; x++)
	{
		LL cur = 0;
		for (auto& c : v)
		{
			cur = (cur * x + c) % MOD;
		}
		if (cur == 0)
		{
			cout << "! " << x << endl;
			return 0;
		}
	}
	cout << "! -1" << endl;
	return 0;
}