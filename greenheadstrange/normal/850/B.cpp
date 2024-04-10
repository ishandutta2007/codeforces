#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define maxn 2000005
using namespace std;
ll ans[maxn];
bool bpr[maxn];
int prms[maxn];
int cnt = 0;
ll b[maxn];
int cnts[maxn];
int main()
{
	for(int i = 0; i < 1007; i++)
		bpr[i] = 1;
	for(int i = 2; i < 1007; i++)
		if(!bpr[i]) continue;
		else
		{
			prms[cnt++] = i;
			for(int j = 2; j * i < 1007; j++)
				bpr[i * j] = 0;
		}
	int n;
	ll x, y;
	scanf("%d%I64d%I64d", &n, &x, &y);
	if(x <= y * 5)
	{
		for(int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			for(int j = 0; j <= x / y; j++)
			{
				int ns = a + j;
				for(int q = 0; q < cnt; q++)
					if(!(ns % prms[q]))
					{
						if(prms[q] > j) 
							ans[prms[q]] += j * y - x;
						while(!(ns % prms[q]))
							ns /= prms[q];
					}
				if(ns != 1) 
					ans[ns] += j * y - x;
			}
		}
		ll lz = n * x;
		ll mns = -1;
		for(int j = 2; j < maxn; j++)
			if(ans[j] + lz < mns || mns == -1)
			    mns = ans[j] + lz;
		printf("%I64d\n", mns);
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			b[i] = a;
			for(int j = 0; j <= 5; j++)
			{
				int ns = a + j;
				for(int q = 0; q < cnt; q++)
					if(!(ns % prms[q]))
					{
						if(prms[q] > j)
							cnts[prms[q]]++;
						while(!(ns % prms[q]))
							ns /= prms[q];
					}
				if(ns != 1) 
					cnts[ns]++;
			}
		}
		ll nms = -1;
		for(int i = 2; i < maxn; i++)
			if(((ll)(n - cnts[i]) * 5 * y) <= nms || nms == -1)
			{
			//	cout<<"CALS"<<i<<endl;
				ll nans = 0;
				for(int j = 1; j <= n; j++)
				{
					ll ns = (b[j] % i);
					if(ns) ns = i - ns;
					ns *= y;
					if(ns > x) ns = x;
					nans += ns;
				}
				if(nms == -1 || nans < nms) nms = nans;
			} 
		printf("%I64d\n", nms);
	}
	return 0;
}