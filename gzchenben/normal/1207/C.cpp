#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long t,n,a,b,c[200005],ans[200005];
long long find0(long long x)
{
	while(c[x]!=0 && x<=n)
	{
		ans[x]=2;
		x++;
	}
	return x;
}
long long find1(long long x)
{
	while(c[x]!=1 && x<=n)
	{
		ans[x]=1;
		x++;
	}
	return x;
}
int main()
{
	scanf("%I64d",&t);
	while(t--)
	{
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		scanf("%I64d%I64d%I64d",&n,&a,&b);
		for(int i=1;i<=n;i++)
		{
			char temp;
			scanf(" %c",&temp);
			if(temp=='1') c[i]=1;
		}
		long long now=1;
		now=find1(now);
		while(1)
		{
			if(now==n+1) break;
			long long temp1=find0(now);
			if(temp1==n+1) break;
			long long temp2=find1(temp1);
			if(temp2==n+1) break;
			if(2*a>(temp2-temp1-1)*b)
			{
				for(long long i=temp1;i<temp2;i++)
				{
					ans[i]=2;
				}
			}
			now=temp2;
		}
		long long sum=a*n;
		for(long long i=1;i<=n;i++)
		{
			if(i!=n && ans[i]!=ans[i+1]) sum+=a;
			sum+=max(ans[i],ans[i+1])*b;
		}
		printf("%I64d\n",sum+b);
	}
}