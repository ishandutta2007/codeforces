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

using namespace std;

typedef unsigned long long ull;

const int MAXN = 200005;

int n,q,l1,l2,len,tot;
int cnt[MAXN];
int pos[MAXN];
int d[MAXN];

ull h1[MAXN];
ull h2[MAXN];
ull pw1[MAXN];
ull pw2[MAXN];

char s[MAXN];

ull gethash1(int l,int r)
{
	return h1[r] - h1[l - 1] * pw1[r - l + 1];
}

ull gethash2(int l,int r)
{
	return h2[r] - h2[l - 1] * pw2[r - l + 1];
}

int main()
{
	scanf("%d%s",&n,s + 1);
	for (int i = 1;i <= n;i++)
	{
		cnt[i] = cnt[i - 1] + (s[i] == '0');
		if (s[i] == '0')
			pos[++tot] = i;
	}
	pw1[0] = pw2[0] = 1;
	for (int i = 1;i < tot;i++)
	{
		d[i] = ((pos[i + 1] - pos[i]) & 1);
		h1[i] = h1[i - 1] * 29 + d[i];
		h2[i] = h2[i - 1] * 10007 + d[i];
		pw1[i] = pw1[i - 1] * 29;
		pw2[i] = pw2[i - 1] * 10007;
	}
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%d%d",&l1,&l2,&len);
		int cnt1 = cnt[l1 + len - 1] - cnt[l1 - 1],st1 = cnt[l1 - 1] + 1,ed1 = cnt[l1 + len - 1];
		int cnt2 = cnt[l2 + len - 1] - cnt[l2 - 1],st2 = cnt[l2 - 1] + 1,ed2 = cnt[l2 + len - 1];
		if (cnt1 != cnt2)
		{
			puts("No");
			continue;
		}
		if (!cnt1)
		{
			puts("Yes");
			continue;
		}
		if ((pos[st1] - l1) % 2 != (pos[st2] - l2) % 2)
		{
			puts("No");
			continue;
		}
		puts(gethash1(st1,ed1 - 1) == gethash1(st2,ed2 - 1) && gethash2(st1,ed1 - 1) == gethash2(st2,ed2 - 1) ? "Yes" : "No");
	}
	return 0;
}