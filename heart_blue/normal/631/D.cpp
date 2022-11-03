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
pair<LL, char> a[N];
pair<LL, char> b[N];
int n, m;
int fail[N];
void getfail(pair<LL, char> str[N], int sz)
{
	fail[1] = 0;
	int j = 0;
	for (int i = 2; i <= sz; i++)
	{
		while (j && str[i] != str[j + 1]) j = fail[j];
		if (str[i] == str[j + 1]) j++;
		fail[i] = j;
	}
}
bool check(pair<LL, char>& p1, pair<LL, char>& p2)
{
	if (p1.second != p2.second) return false;
	return p1.first >= p2.first;
}
void getans()
{
	int sz = m - 2;
	int j = 0;
	int ans = 0;
	for (int i = 1; i + 1 < n; i++)
	{
		while (j && a[i] != b[j + 1]) j = fail[j];
		if (a[i] == b[j + 1]) j++;
		if (j == sz)
		{
			if (check(a[i + 1], b[j + 1]) && check(a[i - sz], b[j - sz])) ans++;
			j = fail[j];
		}
	}
	printf("%d\n", ans);
}
void init(pair<LL, char> a[N], int &n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%lld-%c", &a[i].first, &a[i].second);
		if (i == 0) continue;
		if (a[i].second == a[i - 1].second)
		{
			a[i - 1].first += a[i].first;
			i--, n--;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	init(a, n);
	init(b, m);
	if (m == 1)
	{
		LL ans = 0;
		for (int i = 0; i < n; i++)
			if (check(a[i], b[0]))
				ans += a[i].first - b[0].first + 1;
		printf("%lld\n", ans);
		return 0;
	}
	if (m == 2)
	{
		int ans = 0;
		for (int i = 0; i + 1 < n; i++)
		{
			if (check(a[i], b[0]) && check(a[i + 1], b[1]))
				ans++;
		}
		printf("%d\n", ans);
		return 0;
	}
	getfail(b, m - 2);
	getans();
	return 0;
}