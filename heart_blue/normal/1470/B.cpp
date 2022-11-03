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
const int N = 1e6 + 10;
int a[N];
void init()
{
	for (int i = 1; i < N; i++) a[i] = i;
	for (int i = 2; i * i < N; i++)
	{
		if (a[i] != i) continue;
		int x = i * i;
		for (int j = x; j < N; j += x)
		{
			while (a[j] % x == 0)
				a[j] /= x;
		}
	}
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
		int ans[3] = { 0,0,0 };
		map<int, int> mc;
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int x;
			scanf("%d", &x);
			mc[a[x]]++;
		}
		mc[1];
		for (int o = 0; o < 3; o++)
		{
			int maxv = 0;
			for (auto& p : mc)
			{
				maxv = max(maxv, p.second);
				if (p.first != 1 && p.second % 2 == 0)
				{
					mc[1] += p.second;
					p.second = 0;
				}
			}
			ans[o] = maxv;
		}
		int q;
		scanf("%d", &q);
		while (q--)
		{
			LL w;
			scanf("%lld", &w);
			printf("%d\n", ans[min(w, 2LL)]);
		}
	}
	return 0;
}