#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const long long inf=3e16;
int n,cnt,ans;
long long x[111],y[111],ax,ay,bx,by,xs,ys,t,sum;
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by);
	for (int i=1;;i++)
	{
		x[i]=x[i-1]*ax+bx;
		y[i]=y[i-1]*ay+by;
		if (x[i]>inf || y[i]>inf) 
		{
			cnt=i-1;
			break;
		}
	}
	scanf("%lld%lld%lld",&xs,&ys,&t);
	for (int i=0;i<=cnt;i++)
	{
		for (int j=i;j>=0;j--)
		{
			for (int k=i;k<=cnt;k++)
			{
				sum=abs(xs-x[i])+abs(ys-y[i]);
				bool flag=0;
				for (int h=i;h>j;h--)
				{
					sum+=(abs(x[h]-x[h-1])+abs(y[h]-y[h-1]));
				}
				for (int h=j;h<k;h++)
				{
					sum+=(abs(x[h]-x[h+1])+abs(y[h]-y[h+1]));
				}
				if (sum<=t) 
				{
					flag=1;
				}
				sum=abs(xs-x[i])+abs(ys-y[i]);
				for (int h=k;h>j;h--)
				{
					sum+=(abs(x[h]-x[h-1])+abs(y[h]-y[h-1]));
				}
				for (int h=i;h<k;h++)
				{
					sum+=(abs(x[h]-x[h+1])+abs(y[h]-y[h+1]));
				}
				if (sum<=t) flag=1;
				if (flag) ans=max(ans,k-j+1); 
			}
		}
	}
	printf("%d\n",ans);
	return Accepted;
}