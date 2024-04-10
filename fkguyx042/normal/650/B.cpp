#include <bits/stdc++.h>
#define maxn 520000
using namespace std;

int n,a,b,t;
int v[maxn];
int cur_time,sum,ans;

int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&t);
	char c;
	for (int i=1;i<=n;i++)
	{
		scanf(" %c",&c);
		v[i]=(c=='w');
	}

	cur_time=1+v[1]*b;
	if (cur_time>t)
	{
		printf("%d\n",0);
		return 0;
	}

	ans=sum=1;
	int j=1;
	for (int i=n;i>1;i--)
	{
		if (cur_time+a+1+v[i]*b<=t)
		{
			sum++;
			cur_time+=a+1+v[i]*b;
			j--;
			if (j==0) j=n;
		}
		else
			break;
	}
	ans=max(ans,sum);

	if (ans==n)
	{
		printf("%d\n",n);
		return 0;
	}

	for (int i=2;i<=n;i++)
	{
		cur_time+=2*a+1+v[i]*b;
		sum++;
		while (cur_time>t && j<=n)
		{
			sum--;
			cur_time-=a+1+v[j]*b;
			j++;
		}
		if (cur_time<=t)
			ans=max(ans,sum);
	}

	cur_time=1+v[1]*b;
	sum=1;
	j=1;
	for (int i=2;i<=n;i++)
	{
		if (cur_time+a+1+v[i]*b<=t)
		{
			sum++;
			cur_time=cur_time+a+1+v[i]*b;
			j++;
		}
		else
			break;
	}
	ans=max(ans,sum);
	for (int i=n;i>1;i--)
	{
		cur_time+=2*a+1+v[i]*b;
		sum++;
		while (cur_time>t && j>0)
		{
			sum--;
			cur_time-=a+1+v[j]*b;
			j--;
		}
		if (cur_time<=t)
			ans=max(ans,sum);
	}

	
	printf("%d\n",min(n,ans));
	return 0;
}