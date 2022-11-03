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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int p[N];
int flag[N];
int last[N];
int dp[N][21];
int a[N];
void init()
{
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		for (int j = i + i; j < N; j += i)
			flag[j] = 1;
		p[k++] = i;
	}
}
void refrain(int& x)
{
	for (int i = 0; p[i] * p[i] <= x; i++)
	{
		int o = p[i] * p[i];
		while (x % o == 0) x /= o;
	}
}
void rebuild(int n)
{
	vector<int> v(a + 1, a + n + 1);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	}
	memset(last, 0, sizeof(int) * (v.size() + 1));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	init();
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			refrain(a[i]);
		}
		rebuild(n);
		vector<int> v;
		for (int i = 0; i <= k + 1; i++) v.push_back(0);
		for (int i = 1; i <= n; i++)
		{
			MEM(dp[i], 0x3f);
			if (last[a[i]])
			{
				v.insert(lower_bound(v.begin(), v.end(), last[a[i]]), last[a[i]]);
			}
			last[a[i]] = i;
			while (v.size() > k + 1)
				v.erase(v.begin());
			for (int o = 0; o <= k; o++)
			{
				int id = v[v.size() - o - 1];
				for (int j = 0; j + o <= k; j++)
				{
					dp[i][j + o] = min(dp[i][j + o], dp[id][j] + 1);
				}
			}
		}
		printf("%d\n", dp[n][k]);
	}
	return 0;
}