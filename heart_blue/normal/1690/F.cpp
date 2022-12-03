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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int flag[N];
int cnt[N];
int a[N];
char s[N];
int check(const string& str)
{
	int len = str.length();
	for (int k = 1; k < len; k++)
	{
		if (len % k) continue;
		int ok = 1;
		for (int i = k; i < len; i++)
		{
			if (str[i] != str[i - k])
				ok = 0;
		}
		if (ok) return k;
	}
	return len;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(flag, 0);
		MEM(cnt, 0);
		int n;
		scanf("%d", &n);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
		{
			if (flag[i]) continue;
			int x = i;
			string key;
			while (!flag[x])
			{
				flag[x] = 1;
				key += s[x];
				x = a[x];
			}
			int len = check(key);
			for (int i = 2; i * i <= len; i++)
			{
				int tot = 0;
				while (len % i == 0) tot++, len /= i;
				cnt[i] = max(cnt[i], tot);
			}
			cnt[len] = max(cnt[len], 1);
		}
		LL ans = 1;
		for (int i = 1; i <= n; i++)
		{
			while (cnt[i]--)
				ans *= i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}