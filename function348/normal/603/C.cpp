#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n,k;
int a[N];
int main()
{
	scanf("%d%d",&n,&k);
	k%=2;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (k)
	{
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int t=a[i],p=0,res;
			while (t%2==0) t/=2,p++;
			if (t==1)
			{
				if (p==0) res=1;else
				if (p==1) res=0;else
				if (p%2==0) res=2;else
				res=1;
			}
			if (t==3)
			{
				if (p%2==0) res=1;else res=2;
			}
			if (t>3) 
			{
				if (p==0) res=0;else
				if (p%2==0) res=2;else
				res=1;
			}
			ans^=res;
		}
		if (ans) printf("Kevin\n");else printf("Nicky\n");
	}
	else
	{
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int t=a[i],p=0,res;
			if (t==1) res=1;else
			if (t==2) res=2;else
			if (t%2==0) res=1;else res=0;
			ans^=res;
		}
		if (ans) printf("Kevin\n");else printf("Nicky\n");
	}
	return 0;
}