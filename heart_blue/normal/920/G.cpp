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
const int N = 1e6 + 10;
vector<int> v[N];
int key[N];
int a[N];
void init()
{
	key[0] = 1;
	for (int i = 1; i < N; i++)
		key[i] = -key[i - (i & -i)];
	for (int i = 2; i < N; i++)
	{
		if (!v[i].empty()) continue;
		for (int j = i; j < N; j += i)
			v[j].push_back(i);
	}
}
LL check(LL x, int tot)
{
	LL sum = 0;
	for (int i = 0; i < tot; i++)
	{
		sum += x / a[i] * key[i];
	}
	return sum;
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
		int x, p, k;
		scanf("%d%d%d", &x, &p, &k);
		int n = v[p].size();
		int tot = 1 << n; 
		a[0] = 1;
		for (int i = 0; i < n; i++)
			a[1 << i] = v[p][i];
		for (int i = 1; i < tot; i++)
			a[i] = a[i - (i & -i)] * a[i & -i];
		k += check(x, tot);
		LL l = 1, r = INF * INF;
		LL ans = 1;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			if (check(mid, tot) >= k) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}