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
const int N = 1e6 + 10;
int cnt[N];
vector<LL> check(vector<LL> v)
{
	vector<LL> ret(1 << v.size());
	int sz = ret.size();
	for (int i = 0; i < v.size(); i++)
		ret[1 << i] = v[i];
	for (int i = 1; i < sz; i++)
	{
		ret[i] = ret[i - (i & -i)] + ret[i & -i];
	}
	return ret;
}
int getcnt(LL x)
{
	int ret = 0;
	while (x)
	{
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	int ks = 1;
	for (int i = 1; i < N; i++)
		cnt[i] = cnt[i >> 1] + (i & 1);
	vector<LL> v;
	LL limit = 1e12;
	for (LL i = 4, cur = 6; cur <= limit; cur *= i++)
	{
		v.push_back(cur);
	}
	v = check(v);
	while (ncase--)
	{
		LL n;
		scanf("%lld", &n);
		int ans = INF;
		for (int i = 0; i < v.size(); i++)
		{
			if (n >= v[i])
				ans = min(ans, cnt[i] + getcnt(n - v[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}