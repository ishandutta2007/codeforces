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
const int N = 2e5 + 10;
const int MOD = 998244353;
int cnt[N];
int a[N];
LL check(int n, int x, int o = 0)
{
	string str = to_string(n);
	int i;
	LL ans = 0;
	for (i = 0; i + x < str.length(); i++)
	{
		ans = (ans * 10 + str[i] - '0') % MOD;
	}
	for (; i < str.length(); i++)
	{
		if (o) ans = (ans * 100 + str[i] - '0') % MOD;
		else ans = (ans * 10 + str[i] - '0') * 10 % MOD;
	}
	return ans % MOD * cnt[x] % MOD;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
		cnt[to_string(x).length()]++;
	}
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			ans += check(v[i], j, 0) + check(v[i], j, 1);
		}
	}
	cout << ans % MOD << endl;
	return 0;
}