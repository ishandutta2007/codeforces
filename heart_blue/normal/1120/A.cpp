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
const int N = 5e5 + 10;
int cnt[N];
int cur[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m, k, n, s;
	scanf("%d%d%d%d", &m, &k, &n, &s);
	int tot = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= s; i++)
	{
		int x;
		scanf("%d", &x);
		if (cnt[x]++ == 0)
			tot++;
	}
	for (int i = 0; i < N; i++)
	{
		if (cnt[i] == 0)
			cnt[i] = INF;
	}
	int sum = 0;
	int ptr = 1;
	for (int i = 1; i <= m; i++)
	{
		while (ptr <= m && sum < tot)
		{
			int x = a[ptr++];
			if (++cur[x] == cnt[x])
				sum++;
		}
		if (sum != tot) break;
		int r = max(ptr - 1, i + k - 1);
		if ((i - 1) / k + 1 + (m - r) / k < n)
		{
			int x = a[i];
			if (cur[x]-- == cnt[x])
				sum--;
			continue;
		}
		vector<int> v;
		for (int j = (i - 1) / k * k + 1; j < i; j++)
			v.push_back(j);
		int o = k;
		for (int j = i; j <= r; j++)
		{
			if (cnt[a[j]] != INF && cnt[a[j]] != 0)
			{
				cnt[a[j]]--;
				a[j] = 0;
				o--;
			}
		}
		for (int j = i; j <= r; j++)
		{
			if (a[j] != 0)
			{
				if (o == 0) v.push_back(j);
				else o--;
			}
		}
		printf("%d\n", v.size());
		for (auto& x : v)
			printf("%d ", x);
		return 0;
	}
	puts("-1");
	return 0;
}