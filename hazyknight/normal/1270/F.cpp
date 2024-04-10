#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

const int MAXN = 200005;

int n,tot;
int sum[MAXN];
int p[MAXN];

long long ans;

char s[MAXN];

unordered_map<int,int> cnt;

int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for (int i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] + s[i] - '0';
		if (s[i] == '1')
			p[++tot] = i;
	}
	p[tot + 1] = n + 1;
	for (int k = 1;k <= 100;k++)
	{
		cnt.clear();
		cnt[0]++;
		for (int i = 1;i <= n;i++)
		{
			int v = sum[i] * k - i;
			ans += cnt[v];
			cnt[v]++;
		}
	}
	int st = 100;
	for (int i = 1;i <= tot;i++)
		for (int j = i;(j - i + 1) * st <= n && j <= tot;j++)
		{
			int c1 = j - i + 1,c0 = p[j] - p[i] + 1 - c1,l = p[i] - p[i - 1] - 1,r = p[j + 1] - p[j] - 1;
			if (l > r)
				swap(l,r);
			for (int k = max(st,c0 / c1 + (c0 % c1 != 0));k * c1 <= c0 + l + r;k++)
			{
				int nd = k * c1 - c0;
				if (nd > r)
					nd = l + r - nd;
				if (nd <= l)
					ans += nd + 1;
				else
					ans += l + 1;
			}
		}
	printf("%lld\n",ans);
	return 0;
}