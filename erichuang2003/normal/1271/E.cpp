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

int len;

ll a[64];
ll aa[64];
ll b[64][64];

ll n,k;

ll work(ll *a,int l1,ll *b,int l2)
{
	if (l1 < l2)
		return 0;
	if (!b[0])
		b++,l2--;
	for (int i = l2 - 1;i >= 0;i--)
	{
		if (a[l1 - l2 + i] > b[i])
			return 1ll << (l1 - l2);
		if (a[l1 - l2 + i] < b[i])
			return 0;
	}
	ll sum = 0;
	for (int i = l1 - l2 - 1;i >= 0;i--)
		sum = sum << 1 | a[i];
	return sum + 1;
}

ll cnt(ll *c,int l)
{
	ll sum = work(a,len,c,l);
	for (int i = 1;i < len;i++)
		sum += work(b[i],i,c,l);
	return sum;
}

ll solve(int l)
{
	if (cnt(b[l],l) >= k)
		return (1ll << l) - 1;
	b[l][0] = 0;
	if (cnt(b[l],l) >= k)
	{
		b[l][0] = 1;
		return (1ll << l) - 2;
	}
	b[l][0] = 1;
	ll v = 0;
	for (int i = len - 1;i >= len - l;i--)
		v = v << 1 | a[i];
	if (cnt(aa + len - l,l) >= k)
		return v;
	for (int i = len - l;i < len - 1;i++)
	{
		if (aa[i])
		{
			aa[i]--;
			if (cnt(aa + len - l,l) >= k)
			{
				aa[i]++;
				return v - (1ll << (i - (len - l)));
			}
			aa[i]++;
			break;
		}
	}
	return -1;
}

ll go(ll ans)
{
	ll d[64];
	int lena = 0;
	for (int i = 0;ans;i++,lena = i)
	{
		d[i] = ans & 1;
		ans >>= 1;
	}
	return cnt(d,lena);
}

int main()
{
	scanf("%lld%lld",&n,&k);
	ll N = n;
	for (int i = 0;N;i++,len = i)
	{
		a[i] = N & 1;
		N >>= 1;
	}
	memcpy(aa,a,sizeof(a));
	for (int i = 1;i <= len;i++)
		for (int j = 0;j < i;j++)
			b[i][j] = 1;
	ll low = 1,high = n % 2 ? n : n - 1;
	while (low < high)
	{
		ll mid = low + high >> 1;
		if (~mid & 1)
			mid++;
		if (go(mid) >= k)
			low = mid;
		else
			high = mid - 2;
	}
	if (go(low) < k)
		low = -1;
	ll odd = low;
	low = 2,high = n % 2 ? n - 1 : n;
	while (low < high)
	{
		ll mid = low + high >> 1;
		if (mid & 1)
			mid++;
		if (go(mid) >= k)
			low = mid;
		else
			high = mid - 2;
	}
	if (go(low) < k)
		low = -1;
	printf("%lld\n",max(odd,low));
	return 0;
}