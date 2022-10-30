#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
typedef long long LL;
using namespace std;
void read(LL &x)
{
	char ch;int fu=1;
	while ((ch=getchar())<=32);
	x=0;
	if (ch=='-') fu=-1;else x=ch-48;
	while ((ch=getchar())>32) x=x*10+ch-48;
	x*=fu;
}
int n,k;
int cnt[123456],a[123456];
int main()
{
	scanf("%d%d",&n,&k);
	LL ans=0;
	for (int i=1;i<=n;i++) 
	{
		int x,u=1,flag=0;
		scanf("%d",&x);
		a[i]=1;
		for (int j=2;j*j<=x;j++)
		if (x%j==0)
		{
			int t=0;
			while (x%j==0) t++,x/=j;
			t%=k;
			if (t>0)
			for (int ii=t+1;ii<=k;ii++) 
			{
				if (1LL*u*j>100000) flag=1;
				u=u*j;
			}
			while (t) a[i]*=j,t--;
		}
		if (x!=1) 
		{
			a[i]*=x;
			for (int ii=2;ii<=k;ii++)
			{
				if (1LL*u*x>100000) flag=1;
				u=u*x;
			}
		}
	//	printf("%d %d %d\n",a[i],u,flag);
		if (!flag) ans+=cnt[u];
		cnt[a[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}