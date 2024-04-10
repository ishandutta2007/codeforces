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
const int N = 3e5 + 10;
const int M = 3e5 + 10;
int a[N];
int cnt[N];
int r[N];
int fact[N];
int sz[N];
int dp[M];
int pro[M];
int flag[M];
vector<int> v;
void init()
{
	for (int i = 1; i < N; i++) r[i] = 1;
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i; j < N; j += i)
		{
			a[j] = 1;
			r[j] *= i;
			fact[j] = i;
		}
	}
	for (int i = 2; i < N; i++) v.push_back(r[i]);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int check(int x, int tot)
{
	int n = 0;
	pro[0] = 1;
	while (x > 1)
	{
		pro[1 << n] = fact[x];
		x /= fact[x];
		n++;
	}
	int mask = (1 << n) - 1;
	dp[0] = tot;
	for (int i = 1; i <= mask; i++)
	{
		pro[i] = pro[i - (i&-i)] * pro[i&-i];
		dp[i] = sz[pro[i]];
		flag[i] = INF;
	}
	int sum = 0;
	for (int i = mask; i >= 1; i--)
	{
		for (int s = i; s; s = (s - 1)&i)
		{
			if (i == s) continue;
			dp[s] -= dp[i];
		}
		dp[0] -= dp[i];
	}
	if (dp[0])
		return 1;
	flag[0] = INF;
	for (int i = 1; i <= mask; i++)
	{
		if (dp[i])
		{
			flag[i] = 1;
		}
	}

	queue<int> q;
	for (int i = 1; i <= mask; i++)
	{
		if (flag[i] == 1) q.push(i);
	}
	while (!q.empty())
	{
		int o = q.front(); q.pop();
		for (int i = 1; i <= mask; i++)
		{
			if (i == o) continue;
			if ((flag[i] + flag[o]) < flag[i&o])
			{
				flag[i&o] = flag[i] + flag[o];
				q.push(i&o);
			}
		}
	}
	return flag[0];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	scanf("%d", &n);
	int g = 0;
	int minv = INF;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] = r[a[i]];
		g = gcd(a[i], g);
		minv = min(minv, a[i]);
		cnt[a[i]]++;
	}
	if (minv == 1)
	{
		puts("1");
		return 0;
	}
	if (g > 1)
	{
		puts("-1");
		return 0;
	}
	for (auto &x : v)
	{
		for (int i = x; i < N; i += x)
		{
			sz[x] += cnt[i];
		}
	}
	int ans = n;
	for (int i = 1; i < N; i++)
	{
		if (cnt[i])
			ans = min(check(i, n), ans);
	}
	cout << ans + 1;
	return 0;
}