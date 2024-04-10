#include<cstdio>
#include<iostream>
#define rep(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
const int N=20010;
int n,X,ans=0;
int t[N],h[N],k[N],v[N];
int main()
{
	scanf("%d%d",&n,&X);
	rep(i,1,n) scanf("%d%d%d",&t[i],&h[i],&k[i]);
	
	int x=X;
	int j=0;
	rep(i,1,n)
	if (t[i]==0&&h[i]<=x&&k[i]>=k[j]) j=i;
	if (j)
	{
		v[j]=1;x+=k[j];
		int cnt=1;
		while (1)
		{
			int f=0,l=0;
			rep(i,1,n) 
			if (!v[i]&&t[i]+t[j]==1&&h[i]<=x&&k[i]>=k[l]) {l=i;f=1;}
			if (!f) break;
			v[l]=1;x+=k[l];j=l;
			cnt++;
		}
		rep(i,1,n) v[i]=0;
		ans=max(ans,cnt);
	}
	
	x=X;j=0;
	rep(i,1,n)
	if (t[i]==1&&h[i]<=x&&k[i]>=k[j]) j=i;
	if (j)
	{
		v[j]=1;x+=k[j];
		int cnt=1;
		while (1)
		{
			int f=0,l=0;
			rep(i,1,n) 
			if (!v[i]&&t[i]+t[j]==1&&h[i]<=x&&k[i]>=k[l]) {l=i;f=1;}
			if (!f) break;
			v[l]=1;x+=k[l];j=l;
			cnt++;
		}
		rep(i,1,n) v[i]=0;
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
}