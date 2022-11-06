#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 1000010
#define ll long long
using namespace std;
ll a[N];
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
ll pr[N],t;
int cnt[N];
int main()
{
	int n;
	scanf("%d",&n);
	srand(n*2);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll ans=0;
	for(int _=0;_<=10;_++)
	{
		memset(cnt,0,sizeof(cnt));
		ll x=a[1ll*rand()*rand()%n+1];
		t=0;
		for(int i=1;1ll*i*i<=x;i++)
		if(x%i==0){pr[++t]=i;if(1ll*i*i!=x) pr[++t]=x/i;}
		sort(pr+1,pr+t+1);
		for(int i=1;i<=n;i++)
			cnt[lower_bound(pr+1,pr+t+1,gcd(x,a[i]))-pr]++;
		for(int i=1;i<=t;i++)
			for(int j=i+1;j<=t;j++)
			if(pr[j]%pr[i]==0) cnt[i]+=cnt[j];
		for(int i=t;i;i--)
		if(2*cnt[i]>=n) ans=max(ans,pr[i]);
	}
	printf("%lld\n",ans);
	return 0;
}