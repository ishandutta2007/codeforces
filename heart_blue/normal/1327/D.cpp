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
int flag[N];
int a[N];
int c[N];
int solve(vector<int>& v)
{
	int n = v.size();
	for (int i = 1; i <= n; i++)
	{
		if (n % i) continue;
		for (int j = 0; j < i; j++)
		{
			int ok = 1;
			for (int k = j; k + i < n; k += i)
			{
				if (v[k] != v[k + i])
				{
					ok = 0;
					break;
				}
			}
			if (ok) return i;
		}
	}
	return n;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		int ans = INF;
		fill(flag, flag + n + 1, 0);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
		for (int i = 1; i <= n; i++)
		{
			if (flag[i]) continue;
			int cur = i;
			vector<int> v;
			while (flag[cur] == 0)
			{
				v.push_back(c[cur]);
				flag[cur] = 1;
				cur = a[cur];
			}
			ans = min(ans, solve(v));
		}
		printf("%d\n", ans);
	}
	return 0;
}