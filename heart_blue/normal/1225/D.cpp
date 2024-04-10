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
int multy(int a, int b)
{
	if (a <= INF / b) return a * b;
	else return INF;
}
int powmod(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1) ret = multy(ret, a);
		a = multy(a, a);
		b >>= 1;
	}
	return ret;
}
int a[N];
int b[N];
int check(int& x, int k)
{
	int n = x;
	x = 1;
	int ret = 1;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i) continue;
		int cnt = 0;
		while (n % i == 0) n /= i, cnt++;
		cnt %= k;
		x *= powmod(i, cnt);
		ret = multy(ret, powmod(i, (k - cnt) % k));
	}
	if (n > 1 && k > 1)
	{
		x *= n;
		ret = multy(ret, powmod(n, k - 1));
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = check(a[i], k);
		mc[a[i]]++;
		if (b[i] == INF) continue;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!mc.count(b[i])) continue;
		ans += mc[b[i]] - (a[i] == b[i]);
	}
	cout << ans / 2 << endl;
	return 0;
}