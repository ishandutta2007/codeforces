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

const int MAXN = 200005;
const ll MOD = 1000000007;

int n,q,x,y;
int a[MAXN];
int w[MAXN];

ll sum1[MAXN];
ll sum2[MAXN];

void modify(ll *arr,int p,ll v,bool mod)
{
	while (p <= n)
	{
		arr[p] += v;
		if (mod)
			arr[p] %= MOD;
		p += (p & -p);
	}
}

ll query(ll *arr,int p,bool mod)
{
	ll res = 0;
	while (p >= 1)
	{
		res += arr[p];
		if (mod)
			res %= MOD;
		p -= (p & -p);
	}
	return res;
}

ll sum(ll *arr,int l,int r,bool mod)
{
	if (l > r)
		return 0;
	ll res = query(arr,r,mod) - query(arr,l - 1,mod);
	if (mod)
		res %= MOD;
	return res;
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		a[i] -= i;
	}
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&w[i]);
		modify(sum1,i,w[i],0);
		modify(sum2,i,(ll)a[i] * w[i] % MOD,1);
	}
	while (q--)
	{
		scanf("%d%d",&x,&y);
		if (x < 0)
		{
			x = -x;
			modify(sum1,x,y - w[x],0);
			modify(sum2,x,(ll)a[x] * (y - w[x]) % MOD,1);
			w[x] = y;
		}
		else
		{
			int low = x,high = y;
			ll tot = sum(sum1,x,y,0);
			while (low < high)
			{
				int mid = low + high + 1 >> 1;
				if (sum(sum1,x,mid - 1,0) <= tot / 2)
					low = mid;
				else
					high = mid - 1;
			}
			printf("%lld\n",((sum(sum2,low + 1,y,1) - (sum(sum1,low + 1,y,1) - sum(sum1,x,low - 1,1)) * a[low] % MOD - sum(sum2,x,low - 1,1)) % MOD + MOD) % MOD);
		}
	}
	return 0;
}