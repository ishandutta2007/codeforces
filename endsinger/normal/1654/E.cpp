#include<bits/stdc++.h>
using namespace std;
const int N=100005,bs=65000000,M=bs*2+100;
int n,v[N],s,t,a[M];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int i=0;i<=650;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int w=v[j]-i*j+bs;
			a[w]++;
			s=max(s,a[w]);
		}
		for(int j=1;j<=n;j++)
		{
			int w=v[j]-i*j+bs;
			a[w]--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1&&j>=i-650;j--)
		{
			if(v[j]>=v[i]||(v[i]-v[j])%(i-j)!=0)
				continue;
				int w=(v[i]-v[j])/(i-j);
			a[w]++;
			t=max(t,a[w]);
		}
		for(int j=i-1;j>=1&&j>=i-650;j--)
		{
			if(v[j]>=v[i]||(v[i]-v[j])%(i-j)!=0)
				continue;
				int w=(v[i]-v[j])/(i-j);
			a[w]--;
		}
	}
	for(int i=1;i<=n;i++)
		v[i]=100000-v[i]+1;
	for(int i=0;i<=650;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int w=v[j]-i*j+bs;
			a[w]++;
			s=max(s,a[w]);
		}
		for(int j=1;j<=n;j++)
		{
			int w=v[j]-i*j+bs;
			a[w]--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1&&j>=i-650;j--)
		{
			if(v[j]>=v[i]||(v[i]-v[j])%(i-j)!=0)
				continue;
				int w=(v[i]-v[j])/(i-j);
			a[w]++;
			t=max(t,a[w]);
		}
		for(int j=i-1;j>=1&&j>=i-650;j--)
		{
			if(v[j]>=v[i]||(v[i]-v[j])%(i-j)!=0)
				continue;
				int w=(v[i]-v[j])/(i-j);
			a[w]--;
		}
	}
	printf("%d\n",n-max(s,t+1));
	return 0;
}