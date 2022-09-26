#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 1000005;

int n,tot;
int a[MAXN];
int b[MAXN];
int c[MAXN];

ll ans,sum;

ll cnt(ll v)
{
	int pos = 0;
	ll cur = v,res = 0;
	for (int i = 1;i <= tot;i++)
	{
		if (b[i] < cur)
		{
			cur -= b[i];
			continue;
		}
		pos = i;
		break;
	}
	for (int i = 1;i <= tot;i++)
		res += (ll)abs(pos - i) * b[i];
	return res;
}

void go(ll v)
{
	memcpy(a,c,sizeof(c));
	for (int i = 1;i <= n;i++)
		a[i] %= v;
	ll cur = v,ANS = 0;
	tot = 0;
	for (int i = 1;i <= n;i++)
	{
		if (a[i] < cur)
		{
			cur -= a[i];
			b[++tot] = a[i];
			continue;
		}
		b[++tot] = cur;
		a[i] -= cur;
		cur = v;
		ANS += cnt((v + 1) / 2);
		tot = 0;
		i--;
	}
	ans = min(ans,ANS);
}

int main()
{
	scanf("%d",&n);
	ans = 1e18;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&c[i]);
		sum += c[i];
	}
	if (sum == 1)
	{
		puts("-1");
		return 0;
	}
	for (int i = 2;(ll)i * i <= sum;i++)
		if (sum % i == 0)
		{
			go(i);
			while (sum % i == 0)
				sum /= i;
		}
	if (sum != 1)
		go(sum);
	printf("%lld\n",ans);
	return 0;
}