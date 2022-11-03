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
const int N = 2e5 + 10;
char str[N];
int cnt[200];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		scanf("%s", str + 1);
		if (n % k)
		{
			puts("-1");
			continue;
		}
		MEM(cnt, 0);
		for (int i = 1; i <= n; i++)
			cnt[str[i]]++;
		int tot = 0;
		for (int i = 'a'; i <= 'z'; i++)
		{
			tot += (k - cnt[i] % k) % k;
		}
		if (tot == 0)
		{
			puts(str + 1);
			continue;
		}
		int rest = 0;
		int ok = 0;
		for (int i = n; i >= 1; i--)
		{
			cnt[str[i]]--;
			for (int c = str[i] + 1; c <= 'z'; c++)
			{
				cnt[c]++;
				int cost = 0;
				for (int j = 'a'; j <= 'z'; j++)
				{
					cost += (k - cnt[j] % k) % k;
				}
				if (cost <= n - i && (n - i - cost) % k == 0)
				{
					ok = 1;
					str[i] = c;
					int ptr = i + 1;
					while (cost < n - i) cost++, str[ptr++] = 'a';
					for (int j = 'a'; j <= 'z'; j++)
					{
						while (cnt[j] % k) cnt[j]++, str[ptr++] = j;
					}
				}
				cnt[c]--;
				if (ok) break;
			}
			if (ok) break;
		}
		puts(str + 1);
	}
	return 0;
}