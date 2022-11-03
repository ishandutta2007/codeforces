#include<bits/stdc++.h>
using namespace std;
const long double eps=1e-12;
long long l,r,mid,k;
int n,a[111111];
long long b[111111],sum,cur;
long double cr;
void check(long long x)
{
	for (int i=1;i<=n;i++)
	{
		if (x+a[i]<0)
		{
			b[i]=0;
		}
		else
		{
			cr=(long double)x+(long double)a[i];cr/=3.00;
			cr=sqrt(cr)+eps;
			cur=(long long)cr;
			if (cur>=a[i]) 
			{
				b[i]=a[i];
			}
			else
			{
				if (3ll*cur*cur+3ll*cur+1>=x+a[i]) b[i]=cur;
				else b[i]=cur+1;
			}
		}
	}
}
int main()
{
	scanf("%d%lld",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	l=-4e18;r=4e18;
	while(l<=r)
	{
		mid=(l+r)>>1;
		for (int i=1;i<=n;i++)
		{
			if (mid+a[i]<0)
			{
				b[i]=0;
			}
			else
			{	
				cr=(long double)mid+(long double)a[i];cr/=3.00;
				cr=sqrt(cr)+eps;
				cur=(long long)cr;
				if (cur>=a[i]) 
				{
					b[i]=a[i];
				}
				else
				{
					if (3ll*cur*cur+3ll*cur+1>=mid+a[i]) b[i]=cur;
					else b[i]=cur+1;
				}
			}
		}
		sum=0;
		for (int i=1;i<=n;i++) sum+=b[i];
		if (sum==k)
		{
			break;
		}
		if (sum>k) r=mid-1;
		else l=mid+1;
	}
	if (sum>k)
	{
		check(r);
		sum=0;
		for (int i=1;i<=n;i++) sum+=b[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]<a[i] && 3ll*b[i]*b[i]+3ll*b[i]+1<=r+a[i] && sum<k) 
		{
			b[i]++;
			sum++;
		}
		printf("%lld ",b[i]);
	}
	printf("\n");
	return 0;
}