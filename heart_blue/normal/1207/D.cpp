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
const int MOD = 998244353;
pair<int, int> p[N];
LL fact[N];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = fact[i - 1] * i % MOD;
}
LL solve(int n)
{
	for (int i = 1; i <= n; i++) swap(p[i].first, p[i].second);
	sort(p + 1, p + n + 1);
	LL ans = 1;
	int cnt = 1;
	for (int i = 2; i <= n + 1; i++)
	{
		if (p[i].first != p[i - 1].first)
		{
			ans = ans * fact[cnt] % MOD;
			cnt = 0;
		}
		cnt++;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	scanf("%d", &n);
	p[n + 1] = make_pair(int(INF), int(INF));
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &p[i].first, &p[i].second);
	LL res = fact[n] - solve(n) - solve(n);
	LL ans = 1;
	int cnt = 1;
	sort(p + 1, p + n + 1);
	for (int i = 2; i <= n + 1; i++)
	{
		if (p[i - 1].second > p[i].second)
		{
			ans = 0;
			break;
		}
		if (p[i] != p[i - 1])
		{
			ans = ans * fact[cnt] % MOD;
			cnt = 0;
		}
		cnt++;
	}
	res += ans;
	res %= MOD;
	if (res < 0) res += MOD;
	cout << res << endl;
	return 0;
}