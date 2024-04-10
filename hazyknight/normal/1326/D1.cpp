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

typedef long long ll;

const int MAXN = 1000005;
const ll m1 = 29;
const ll m2 = 10007;
const ll md1 = 998244353;
const ll md2 = 1000000009;

int T,n,k;

ll pw1[MAXN];
ll pw2[MAXN];

pair<ll,ll> hb[MAXN];
pair<ll,ll> hf[MAXN];

char s[MAXN];

pair<ll,ll> getf(int l,int r)
{
	return make_pair(((hf[r].first - hf[l - 1].first * pw1[r - l + 1]) % md1 + md1) % md1,((hf[r].second - hf[l - 1].second * pw2[r - l + 1]) % md2 + md2) % md2);
}

pair<ll,ll> getb(int l,int r)
{
	return make_pair(((hb[l].first - hb[r + 1].first * pw1[r - l + 1]) % md1 + md1) % md1,((hb[l].second - hb[r + 1].second * pw2[r - l + 1]) % md2 + md2) % md2);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s + 1);
		n = strlen(s + 1);
		pw1[0] = 1;
		for (int i = 1;i <= n;i++)
			pw1[i] = pw1[i - 1] * m1 % md1;
		pw2[0] = 1;
		for (int i = 1;i <= n;i++)
			pw2[i] = pw2[i - 1] * m2 % md2;
		for (int i = 1;i <= n;i++)
		{
			hf[i].first = (hf[i - 1].first * m1 + s[i] - 'a') % md1;
			hf[i].second = (hf[i - 1].second * m2 + s[i] - 'a') % md2;
		}
		hb[n + 1].first = hb[n + 1].second = 0;
		for (int i = n;i >= 1;i--)
		{
			hb[i].first = (hb[i + 1].first * m1 + s[i] - 'a') % md1;
			hb[i].second = (hb[i + 1].second * m2 + s[i] - 'a') % md2;
		}
		int l = 1,r = n;
		while (l < r)
		{
			if (s[l] != s[r])
				break;
			l++,r--;
		}
		int L = 1,R = 0;
		for (int i = l;i <= r;i++)
		{
			if (getf(l,i) == getb(l,i))
				if (R - L + 1 < i - l + 1)
				{
					L = l;
					R = i;
				}
		}
		for (int i = r;i >= l;i--)
		{
			if (getb(i,r) == getf(i,r))
				if (R - L + 1 < r - i + 1)
				{
					L = i;
					R = r;
				}
		}
		for (int i = 1;i < l;i++)
			putchar(s[i]);
		for (int i = L;i <= R;i++)
			putchar(s[i]);
		for (int i = r + 1;i <= n;i++)
			putchar(s[i]);
		putchar('\n');
	}
	return 0;
}