#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const long double pi=acos(-1),eps=1e-7;
int n,cnt,r;
long long ans;
int x[3333],y[3333];
pair<int,int> a[6666];
long long cross(int x1,int x2,int x3,int x4)
{
	return (1ll*x1*x4-1ll*x2*x3);
}
int cc(pair<int,int> a)
{
	if (a.first>0) 
	{
		if (a.second>0) return 1;
		return 2;
	}
	else
	{
		if (a.second>0) return 4;
		return 3;
	}
}
bool cmp(pair<int,int> a,pair<int,int> b)
{
	if (cc(a)!=cc(b)) return cc(a)<cc(b);
	return cross(a.first,a.second,b.first,b.second)<0;
}
long long c4(int x)
{
	if (x<0) return 0;
	return (1ll*x*(x-1)*(x-2)*(x-3)/24);
}
long long c3(int x)
{
	if (x<0) return 0;
	return (1ll*x*(x-1)*(x-2)/6);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for (int i=1;i<=n;i++)
	{
		cnt=0;
		for (int j=1;j<=n;j++)
		{
			if (i==j) continue;
			a[++cnt]=make_pair(x[j]-x[i],y[j]-y[i]);
		}
		sort(a+1,a+cnt+1,cmp);
		for (int j=1;j<=cnt;j++) 
		{
			a[cnt+j]=a[j];
		}
		ans+=c4(cnt);
		r=1;
		for (int j=1;j<=cnt;j++)
		{
			while(r<=2*cnt && (cross(a[j].first,a[j].second,a[r].first,a[r].second)<0 || r<=j)) r++;
			ans-=c3(r-j-1);
		}
	}
	printf("%lld\n",ans);
	return Accepted;
}