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
const int N = 1e3 + 10;

LL mr[N];
LL tot[N];
int getlayer(LL x)
{
	int cnt = 0;
	while (x)
	{
		cnt++;
		x >>= 1;
	}
	return cnt;
}
LL getans(LL o, LL pos)
{
	pos -= mr[o];
	if (pos < 0) pos += tot[o];
	return (1LL << (o - 1)) + pos;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tot[1] = 1;
	for (int i = 2; i < 64; i++) tot[i] = tot[i - 1] << 1;
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			LL x, k;
			scanf("%lld%lld", &x, &k);
			int o = getlayer(x);
			k %= tot[o];
			if (k < 0) k += tot[o];
			mr[o] = (mr[o] + k) % tot[o];
			continue;
		}
		if (op == 2)
		{
			LL x, k;
			scanf("%lld%lld", &x, &k);
			int o = getlayer(x);
			k %= tot[o];
			if (k < 0) k += tot[o];
			for (int i = o; i < 64; i++)
			{
				mr[i] = (mr[i] + k) % tot[i];
				k <<= 1;
			}
			continue;
		}
		if (op == 3)
		{
			LL x;
			scanf("%lld", &x);
			int o = getlayer(x);
			LL pos = (x - tot[o] + mr[o]) % tot[o];
			for (int i = o; i >= 1; i--) printf("%lld ", getans(i, pos)), pos >>= 1;
			puts("");
		}
	}
	return 0;
}