#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
int a[N];
ll C2(int n){return 1ll*n*(n-1)/2;}
int main()
{
	int n,d;
	ll ans=0;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=1;
	for(l=1;l<=n;l++)
	{
		while(r<=n && a[r]-a[l]<=d) r++;
		r--;
		ans+=max(0ll,C2(r-l));
	}
	printf("%lld\n",ans);
	return 0;
}