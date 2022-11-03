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
const int N = 1e5 + 100;
int a[N];
int p[N];
void init()
{
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		p[k++] = i;
		for (int j = i + i; j < N; j += i) a[j] = 1;
	}
}
void check(LL n)
{
	vector<pair<int, LL>> v;
	LL x = n;
	for (int i = 0; p[i] <= n / p[i]; i++)
	{
		if (n % p[i]) continue;
		int cnt = 0;
		while (n % p[i] == 0)
		{
			cnt++;
			n /= p[i];
		}
		v.emplace_back(cnt, p[i]);
	}
	if (n > 1) v.emplace_back(1, n);
	sort(v.rbegin(), v.rend());
	printf("%d\n", v.front().first);
	int tot = v.front().first;
	while (--tot) printf("%lld ", v.front().second), x /= v.front().second;
	printf("%lld\n", x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL n;
		scanf("%lld", &n);
		check(n);
	}
	return 0;
}