#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[2000005];
ll sum,m;
bool cmp(int x,int y)
{
	return x>y;
}
bool check(int d)
{
	ll ret=0,mi=0;
	for(int i=1;i<=n;i+=d,mi++)
	{
		for(int j=i;j<=min(n,i+d-1);j++) ret+=max(0ll,a[j]-mi);
	}
	return ret>=m;
}
int main()
{
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	if(sum<m) 
	{
		printf("-1");
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	int l=1,r=n;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(check(l)) printf("%d\n",l);
	else printf("%d\n",r);
	return 0;
}/*
2 4
1 2 -3 2
1 2
1 3
1 4
1 2
1 3
3 4
1 -1*/