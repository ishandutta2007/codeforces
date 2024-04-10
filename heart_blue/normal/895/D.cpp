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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
LL fact[N];
LL rfact[N];
char s1[N];
char s2[N];
int cnt[200];
int n;
LL ans = 0;
LL cur = 0;
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % INF;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++) rfact[i] = (INF - INF / i) * rfact[INF % i] % INF;
	for (int i = 2; i < N; i++) rfact[i] = rfact[i] * rfact[i - 1] % INF;
}
LL getans()
{
	LL res = 1;
	int sum = 0;
	for (int i = 'a'; i <= 'z'; i++)
	{
		sum += cnt[i];
		res = res * rfact[cnt[i]] % INF;
	}
	return res % INF;
}
inline void del(int x)
{
	cur = cur * fact[x] % INF;
}
inline void add(int x)
{
	cur = cur * rfact[x] % INF;
}
void dfs(int pos, bool limit1 = true, bool limit2 = true)
{
	if (!limit1 && !limit2)
	{
		ans += cur * fact[n - pos + 1] % INF;
		return;
	}
	if (pos > n)
	{
		return;
	}
	int lo = 'a';
	int up = 'z';
	if (limit1) lo = s1[pos];
	if (limit2) up = s2[pos];
	for (int i = lo; i <= up; i++)
	{
		if (cnt[i] == 0) continue;
		del(cnt[i]--);
		add(cnt[i]);
		dfs(pos + 1, limit1 && i == s1[pos], limit2 && i == s2[pos]);
		del(cnt[i]++);
		add(cnt[i]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	scanf("%s%s", s1 + 1, s2 + 1);
	n = strlen(s1 + 1);
	for (int i = 1; i <= n; i++)
		cnt[s1[i]]++;
	cur = getans();
	dfs(1);
	printf("%lld\n", ans % INF);
	return 0;
}