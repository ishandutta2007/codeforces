#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000010;
typedef long long LL;
int n,x,y;
int a[N];
LL f1[N],f2[N],g1[N],g2[N];
LL ans;
void check(int d)
{
	int l=n+1,r=0;
	for (int i=1;i<=n;i++)
	if (a[i]%d!=0)
	{
		if ((a[i]-1)%d!=0&&(a[i]+1)%d!=0) l=min(l,i),r=max(r,i);
	}
	LL now=1LL*(r-l+1)*x;
	if (r==0) now=0;
	LL p1=1e+18,p2=1e+18;int cnt=0;
	for (int i=1;i<=n;i++)
		if (a[i]%d!=0) f1[i]=f1[i-1]+y;else f1[i]=f1[i-1];
	for (int i=n;i>=1;i--)
		if (a[i]%d!=0) f2[i]=f2[i+1]+y;else f2[i]=f2[i+1];
	if (r!=0)
	{
		for (int i=0  ;i<l;i++) p1=min(p1,f1[i]+1LL*(l-i-1)*x);
		for (int i=n+1;i>r;i--) p2=min(p2,f2[i]+1LL*(i-r-1)*x);
		ans=min(ans,now+p1+p2);
	}
	else
	{
		for (int i=1;i<=n;i++) g1[i]=min(g1[i-1]+x,f1[i]);
		for (int i=n;i>=1;i--) g2[i]=min(g2[i+1]+x,f2[i]);
		now=1e+18;
		for (int i=0;i<=n;i++) now=min(now,g1[i]+g2[i+1]);
		ans=min(ans,now);
	}
	
}
void calc(int tmp)
{
	for (int i=2;i*i<=tmp;i++)
	if (tmp%i==0)
	{
		check(i);
		while (tmp%i==0) tmp/=i;
	}
	if (tmp!=1) check(tmp);
}
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int tmp;ans=1e+18;
	
	calc(a[1]);calc(a[1]+1);calc(a[1]-1);
	calc(a[n]);calc(a[n]+1);calc(a[n]-1);
	
	cout<<ans<<endl;
	return 0;
}