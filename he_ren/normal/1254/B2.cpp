#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

int n,a[MAXN];
ll sum[MAXN];

ll gao(ll p)
{
	ll res=0;
	for(int i=1; i<=n; ++i)
	{
		ll tmp = sum[i]%p;
		res += min(tmp, p-tmp);
	}
	return res;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1]+a[i];
	if(sum[n]==1){ printf("-1"); return 0;}
	
	ll ans = linf, tmp = sum[n];
	int ss = sqrt(tmp);
	for(int i=2; i<=ss && tmp>1; ++i)
		if(tmp%i==0)
		{
			while(tmp%i==0) tmp/=i;
			chk_min(ans, gao(i));
		}
	if(tmp>1) chk_min(ans, gao(tmp));
	printf("%lld",ans);
	return 0;
}