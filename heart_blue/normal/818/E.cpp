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
const int N = 1e5 + 10;
int a[30];
int cnt[30];
int sum[N][30];
int sz = 0;
void build(int k)
{
	for (int i = 2; i * i <= k; i++)
	{
		if (k % i) continue;
		int c = 0;
		while (k % i == 0) k /= i, c++;
		a[sz] = i;
		cnt[sz] = c;
		sz++;
	}
	if (k > 1)
	{
		a[sz] = k;
		cnt[sz] = 1;
		sz++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	build(k);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		memcpy(sum[i], sum[i - 1], sizeof(sum[i]));
		for (int j = 0; j < sz; j++)
		{
			int c = 0;
			while (x % a[j] == 0) x /= a[j], c++;
			sum[i][j] += c;
		}
	}
	LL ans = 0;
	int ptr = 1;
	for (int i = 1; i <= n; i++)
	{
		ptr = max(ptr, i);
		while (ptr <= n)
		{
			int flag = 1;
			for (int j = 0; j < sz; j++)
			{
				if (sum[ptr][j] - sum[i - 1][j] < cnt[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag) break;
			ptr++;
		}
		ans += n - ptr + 1;
	}
	printf("%lld\n", ans);
	return 0;
}